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
#include <memory>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QFrame
{
    Q_OBJECT

private:
    std::shared_ptr<life::ParametersManager> parameterManager;
    QMap<QString, QVariant> parameters;
    Ui::SettingsPage *ui;

public:
    explicit SettingsPage(QWidget *parent = 0);

    ~SettingsPage();

    void init(const std::shared_ptr<life::ParametersManager>& parameterManager);

public slots:
    void reset();

    bool save();

private:
    template<typename T>
    QLayout* widgetFactory(const T& machineParameter) {

        using namespace life::machineparameters;

        static_assert(isMachineParameter<T>::value, "T must be a machine parameter");
        using type = typename isMachineParameter<T>::type;
        auto& mp = static_cast<const MachineParameter<type>&>(machineParameter);

        QHBoxLayout* hLayout = new QHBoxLayout();
        auto label = new QLabel(mp.key, this);

        hLayout->addWidget(label);

        if (std::is_same<QString, type>::value) {
            auto widget = new QLineEdit(this);
            for (auto&& value : mp.options)
                if (value == MachineParameterOption::IP_ADDRESS)
                    widget->setInputMask("000.000.000.000");
            widget->setObjectName(mp.key);
            hLayout->addWidget(widget);
            connect(widget, &QLineEdit::textEdited, [=](const QString& text) {
                parameters[mp.key] = text;
            });

        } else if (std::is_same<bool, type>::value) {
            auto widget = new QCheckBox(this);
            widget->setObjectName(mp.key);
            connect(widget, &QCheckBox::stateChanged, [=](int state) {
                parameters[mp.key] = (state == Qt::CheckState::Checked) ? true : false;
            });
            hLayout->addWidget(widget);

        } else if (std::is_integral<type>::value) {
            auto widget = new QSpinBox();
            widget->setObjectName(mp.key);
            widget->setSuffix(" "+mp.unitMeasure);
            widget->setRange(0, std::numeric_limits<int>::max());
            connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int value) {
                parameters[mp.key] = value;
            });
            hLayout->addWidget(widget);

        } else if (std::is_enum<type>::value) {
            auto widget = new QComboBox();
            widget->setObjectName(mp.key);
            if (std::is_same<type, AxisXFeedback>::value) {
                for (auto&& item: AxisXFeedbackStr)
                    widget->addItem(item);

                connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated), [=](int index) {
                    parameters[mp.key] = life::machineparameters::AxisXFeedbackStr[index];
                });

            } else if (std::is_same<type, AxisXKind>::value) {
                for (auto&& item: AxisXKindStr)
                    widget->addItem(item);

                connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated), [=](int index) {
                    parameters[mp.key] = life::machineparameters::AxisXKindStr[index];
                });

            } else if (std::is_same<type, GuiUnitMeasure>::value) {
                for (auto&& item: GuiUnitMeasureStr)
                    widget->addItem(item);

                connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated), [=](int index) {
                    parameters[mp.key] = life::machineparameters::GuiUnitMeasureStr[index];
                });

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

    void createConnections();

    void model2View();

    void view2Model();

private slots:
    void removeAllWidgets();

};

#endif // SETTINGSPAGE_HPP
