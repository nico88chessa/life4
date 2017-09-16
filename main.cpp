#include <iostream>
#include <LaserDutyProfile.hpp>
#include <Profile.hpp>
#include <MathUtils.hpp>
#include <QtDebug>


int main(int argc, char** argv) {

    LaserDutyProfile profile(100, 69, 5);
    profile.setDuty(80);
    profile.setDuty(70);
    profile.setDuty(0);

    Profile<LaserDutyProfile> prova("prova", 1, 1000, 2);
    qDebug() << std::is_same<LaserDutyProfile, LaserDutyProfile>();
    prova.getPixelTime();
    qDebug() << isLaserBaseProfile<LaserDutyProfile>::value;

    LaserDutyProfile test = prova.getLaserConfiguration();

    Profile<LaserDutyProfile> prova2;
    prova2.getPixelTime();

    Profile<LaserPulsedProfile> provaPulsed;
    provaPulsed.getPixelTime();

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
