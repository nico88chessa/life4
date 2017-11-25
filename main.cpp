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
#include <memory>
#include <ui/SettingsPage.hpp>

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

int main(int argc, char** argv) {

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

//    life::MachineParameters mp;
//    mp.flush();

//    auto value = mp.getValue(life::machineparameters::AXISX_ACC);

//    valueIsOF<1>::type vTest1 = "true";
//    valueIsOF<2>::type vTest2 = 2;
//    valueIsOF<3>::type* vTest3 = nullptr;

//    life::MachineDigitalIO mdi;
//    mdi.flush();

//    return 0;
}

