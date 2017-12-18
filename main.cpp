#include <core/data/LaserDutyProfile.hpp>
#include <core/data/Profile.hpp>
#include <global/utils/MathUtils.hpp>
#include <QtDebug>
#include <configure.h>
#include <MainWindow.hpp>
#include <QApplication>
#include <QFile>
#include <QTranslator>
#include <core/data/Parameters.hpp>
#include <widgets/UnmovableMainWindow.hpp>
#include <CylinderDialog.hpp>
#include <core/data/DigitalIO.hpp>
#include <iostream>
#include <memory>
#include <ui/SettingsPage.hpp>
#include <core/logic/ParametersManager.hpp>
#include <QtGlobal>
#include <QtCore>
#include <QTranslator>
#include <QApplication>
#include <QMainWindow>
#include <core/data/AnalogicIO.hpp>

//DECL_STANDARD_ANALOGIC_IO_DOUBLE(MirrorTemperature2, 1, PLC, INPUT, true, "Mirror temperature too high!", 1.0, 20.0, 40.0, 1.0, 0.0, °C)

template <typename T>
class A {
public:
    virtual T getValue() const {
        return v;
    }

protected:
    T v;
};

template <typename T>
class B : public A<T> {
public:
    virtual T getValue() const {
        return A<T>::v + A<T>::v;
    }
};

template <quint32> struct valueIsOF { using type = void; };
template <> struct valueIsOF<1> { using type = QString; };
template <> struct valueIsOF<2> { using type = char; };

using namespace life;


int main(int argc, char** argv) {

/********************* PER TRADUZIONI *********************************

    QApplication application(argc, argv);
    QTranslator translator;

    translator.load("LIFE_IT.qm");
    application.installTranslator(&translator);

    QString prova = application.translate("Header", AnalogicMirrorTemperature.alarmText.toLatin1());
    //KO --> Context translation errato QString prova2 = application.tr(AnalogicMirrorTemperature.alarmText.toLatin1());
    //KO --> Context translation errato QString prova3 = application.tr(AnalogicMirrorTemperature.alarmText.toLatin1(), "Header");
    //KO --> Context translation errato QString prova4 = application.tr("Header", AnalogicMirrorTemperature.alarmText.toLatin1());

**********************************************************************/


/*****************************************************

    std::vector<std::shared_ptr<life::SimpleIO> > vet;

    auto prova1 = std::make_shared<life::AnalogicIOFloat>(life::AnalogicMirrorTemperature);

    vet.push_back(prova1);

    auto testVar = vet.at(0);
    if (auto testVar2 = std::dynamic_pointer_cast<life::AnalogicIODouble>(testVar))
        qDebug() << "OK";

    if (auto testVar3 = std::dynamic_pointer_cast<life::AnalogicIOFloat>(testVar))
        qDebug() << "NOK";

    qDebug() << life::ANALOGIC_PARAMETER_NAME;
    QString test2 = life::ANALOGIC_PARAMETER_NAME;
*****************************************************/


    qDebug() << "size: " << life::machineparameters::AxisXFeedbackStr[static_cast<int>(life::machineparameters::AxisXFeedback::linear)];
    qDebug() << "size: " << life::machineparameters::AxisXFeedbackSize;
    qDebug() << "size: " << life::machineparameters::AxisXKindSize;

    QApplication app(argc, argv);

    MainWindow test;
    test.show();

    return app.exec();


/*****************************************************
 *
    auto test1 = std::make_shared<B<int> >();
    auto test2 = std::make_shared<A<int> >();
    auto test3 = std::make_shared<A<int> >();

    std::vector<std::shared_ptr<A<int> > > vet;

    vet.push_back(std::move(test1));
    vet.push_back(std::move(test2));
    vet.push_back(std::move(test3));

    auto test = vet.at(0);
    using testType = std::remove_reference<decltype(*test)>::type;
    auto v = dynamic_cast<B<float>*>(vet.at(0).get());
    auto v2 = dynamic_cast<B<int>*>(vet.at(0).get());
    qDebug() << v2->getValue();
    if (std::is_base_of< A<int>, testType >::value) {
        auto testCasting = std::dynamic_pointer_cast<B<int> >(test2);
        qDebug() << "OK";
    } else
        qDebug() << "NOK";

    qDebug() << "test type: " << typeid(*test).name();

*****************************************************/

/*****************************************************
    life::ParametersManager mp;

    auto t = mp.getIO<decltype(AnalogicMirrorTemperature)>("AnalogicMirrorTemperatu");
    qDebug() << "count: " << t.use_count();
    qDebug() << "lowerLimit: " << t->lowerLimit;
    mp.flush();

    auto value = mp.getValue(life::machineparameters::AXISX_ACC);

    return 0;
*****************************************************/

}
