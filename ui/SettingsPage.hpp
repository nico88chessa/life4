#ifndef SETTINGSPAGE_HPP
#define SETTINGSPAGE_HPP

#include <QFrame>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <core/data/Parameters.hpp>
#include <core/logic/ParametersManager.hpp>
#include <type_traits>
#include <QObject>
#include <widgets/DoubleLineEdit.hpp>
#include <widgets/IntLineEdit.hpp>
#include <QSpinBox>
#include <QDoubleSpinBox>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QFrame
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = 0);
    ~SettingsPage();

private:
    life::ParametersManager parameterManager;

private slots:
    void removeAllWidgets();

    void updateSetting();

private:
    Ui::SettingsPage *ui;

    template<typename T>
    QLayout* widgetParameter(const T& machineParameter) {

        using namespace life::machineparameters;

        static_assert(isMachineParameter<T>::value, "T must be a machine parameter");
        using type = typename isMachineParameter<T>::type;
        constexpr auto options = isMachineParameter<T>::optionSize;
        auto& mp = static_cast<const MachineParameter<type, options>&>(machineParameter);

        QHBoxLayout* hLayout = new QHBoxLayout();
        auto label = new QLabel(mp.key, this);

        hLayout->addWidget(label);

        if (std::is_same<QString, type>::value) {
            auto widget = new QLineEdit(this);
            for (auto value : mp.options)
                if (value == MachineParameterOption::IP_ADDRESS)
                    widget->setInputMask("000.000.000.000");
            widget->setObjectName(mp.key);
            hLayout->addWidget(widget);
            connect(widget, &QLineEdit::editingFinished, this, &SettingsPage::updateSetting);

        } else if (std::is_same<bool, type>::value) {
            auto widget = new QCheckBox(this);
            widget->setObjectName(mp.key);
            connect(widget, &QCheckBox::clicked, this, &SettingsPage::updateSetting);
            hLayout->addWidget(widget);

        } else if (std::is_integral<type>::value) {
            auto widget = new QSpinBox();
            widget->setObjectName(mp.key);
            widget->setSuffix(" "+mp.unitMeasure);
            widget->setRange(0, std::numeric_limits<int>::max());
            connect(widget, &QSpinBox::editingFinished, this, &SettingsPage::updateSetting);
            hLayout->addWidget(widget);

        } else if (std::is_enum<type>::value) {
            auto widget = new QComboBox();
            widget->setObjectName(mp.key);
            if (std::is_same<type, AxisXFeedback>::value) {
                for (auto item: AxisXFeedbackStr)
                    widget->addItem(item);
            } else if (std::is_same<type, AxisXKind>::value) {
                for (auto item: AxisXKindStr)
                    widget->addItem(item);
            } else if (std::is_same<type, GuiUnitMeasure>::value) {
                for (auto item: GuiUnitMeasureStr)
                    widget->addItem(item);
            }
            hLayout->addWidget(widget);
        }


        /* else if (std::is_floating_point<type>::value) {
            auto widget = new QDoubleSpinBox();
            widget->setObjectName(mp.key);
            widget->setSuffix(" "+mp.unitMeasure);
            widget->setMaximum(std::numeric_limits<double>::max());
            connect(widget, &QDoubleSpinBox::editingFinished, this, &SettingsPage::updateSetting);
            hLayout->addWidget(widget);
        }*/

        return hLayout;
    }

    void setupGraphics();

    void model2View();

    void view2Model();

};

#endif // SETTINGSPAGE_HPP
