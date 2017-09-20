#include <core/data/LaserDutyProfile.hpp>
#include <core/data/Profile.hpp>
#include <MathUtils.hpp>
#include <QtDebug>
#include <configure.h>
#include <MainWindow.hpp>
#include <QApplication>
#include <QFile>
#include <QTranslator>
#include <ui/CylinderDialog.hpp>
#include <core/data/MachineParameters.hpp>
#include <widgets/UnmovableMainWindow.hpp>

int main(int argc, char** argv) {

    QString prova(QObject::tr("fmsasdeo"));
    QString prova2(QObject::tr("PROVA2"));

    life::MachineParameters params;

    params.setValue(life::machineparameters::PREF_GUI_LANGUAGE, "EN");

    params.flush();

    //LaserDutyProfile profile(100, 69, 5);
    //profile.setDuty(80);
    //profile.setDuty(70);
    //profile.setDuty(0);
    //
    //Profile<LaserDutyProfile> prova("prova", 1, 1000, 2);
    //qDebug() << std::is_same<LaserDutyProfile, LaserDutyProfile>();
    //prova.getPixelTime();
    //qDebug() << isLaserBaseProfile<LaserDutyProfile>::value;
    //
    //LaserDutyProfile test = prova.getLaserConfiguration();
    //
    //Profile<LaserDutyProfile> prova2;
    //prova2.getPixelTime();
    //
    //Profile<LaserPulsedProfile> provaPulsed;
    //provaPulsed.getPixelTime();

    //Profile<LaserDutyProfile> prova("prova", 1, 1000, 2, 10, 7, 2);
    //
    //LaserDutyProfile pro = prova.getLaserConfiguration();

    QApplication app(argc, argv);

    QFile file(":/styles/style1.qss");
    if (!file.open(QFile::ReadOnly))
        return 0;
    QString styleSheet = QLatin1String(file.readAll());
    app.setStyleSheet(styleSheet);

    QTranslator translator;
    qDebug() << "loading: " << translator.load(":/lang/LIFE_EN.qm");
    app.installTranslator(&translator);

    QTranslator translator2;
    qDebug() << "loading: " << translator2.load(":/lang/LIFE_IT.qm");
    app.installTranslator(&translator2);


    MainWindow mainWindow;
    mainWindow.show();

    CylinderDialog dialog;
    dialog.show();


    app.exec();

    qDebug() << life::LIFE_VERSION;
    qDebug() << life::APPLICATION_NAME;

    return 0;
}

//<?xml version="1.0" encoding="UTF-8"?>
//<profiles>
//    <profile id="1">
//        <title>test</title>
//        <imageResolution>1000.000</imageResolution>
//        <laserKind>YAGP</laserKind>
//        <laserSources>1</laserSources>
//        <laserMin>0.00</laserMin>
//        <laserMax>1.00</laserMax>
//        <laserShots>1</laserShots>
//        <laserPeriod>1.00</laserPeriod>
//        <referenceDiameter>5.000</referenceDiameter>
//        <referenceSpeed>10</referenceSpeed>
//        <referenceZ>0.000</referenceZ>
//    </profile>
//</profiles>
