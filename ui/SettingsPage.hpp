#ifndef SETTINGSPAGE_HPP
#define SETTINGSPAGE_HPP

#include <QFrame>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <core/data/Parameters.hpp>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QFrame
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = 0);
    ~SettingsPage();

private slots:
    void removeAllWidgets();

    void updateSetting();

private:
    Ui::SettingsPage *ui;

    template<typename T>
    QLayout* widgetFactory(const T& machineParameter) {

        using namespace life::machineparameters;

        static_assert(isMachineParameter<T>::value, "T mush be a machine parameter");
        using type = typename isMachineParameter<T>::type;
        auto& mp = static_cast<const MachineParameter<type>&>(machineParameter);

        QVBoxLayout* vLayout = new QVBoxLayout(this);
        QHBoxLayout* hLayout = new QHBoxLayout(this);
        vLayout->addLayout(hLayout);

        auto label = new QLabel(mp.key, this);
        hLayout->addWidget(label);

        if (std::is_same<QString, type>::value) {
            auto le = new QLineEdit(this);
            le->setObjectName(mp.key);
            le->setText(QString(mp.defaultValue));
            hLayout->addWidget(le);
            connect(le, &QLineEdit::editingFinished, this, &SettingsPage::updateSetting);
//            return le;

        } else if (std::is_same<bool, type>::value) {
            auto cb = new QComboBox(this);
            cb->setObjectName(mp.key);
            cb->addItem(tr("True"));
            cb->addItem(tr("False"));
            connect(cb, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated), this, &SettingsPage::updateSetting);
            hLayout->addWidget(cb);
//            return cb;
        }
        return vLayout;
//        return nullptr;

    }



};

#endif // SETTINGSPAGE_HPP
