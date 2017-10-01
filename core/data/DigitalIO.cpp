#include "DigitalIO.hpp"

using namespace life;

static constexpr char DIGITAL_ARRAY_NAME[] = "DigitalIO";

#define DECL_STANDARD_DIGITAL_IO(NAME, CHANNEL, DEVICE, DIRECTION, IS_ALARM, ALARM_TEXT, INVERT_LOGIC) \
    static const DigitalIO Digital##NAME = { #NAME, CHANNEL, DEVICE, DIRECTION, IS_ALARM, #ALARM_TEXT, INVERT_LOGIC };

DECL_STANDARD_DIGITAL_IO(Power, 0, CN, INPUT, false, , false)
DECL_STANDARD_DIGITAL_IO(Cycle, 1, CN, INPUT, false, , false)
DECL_STANDARD_DIGITAL_IO(Enable, 2, PLC, OUTPUT, false, , false)
DECL_STANDARD_DIGITAL_IO(LaserPower, 3, PLC, OUTPUT, false, , false)
DECL_STANDARD_DIGITAL_IO(GreenLamp, 4, PLC, OUTPUT, false, , false)
DECL_STANDARD_DIGITAL_IO(RedLamp, 5, PLC, OUTPUT, false, , false)


MachineDigitalIO::MachineDigitalIO() {
    load();
}

void MachineDigitalIO::load() {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    int size = settings.beginReadArray(DIGITAL_ARRAY_NAME);
    for (int i=0; i<size; ++i) {
        settings.setArrayIndex(i);
        DigitalIO io;
        io.name = settings.value("name").value<QString>();
        io.channel = settings.value("channel").value<quint32>();
        io.device = str2DeviceType(settings.value("device").value<QString>());
        io.direction = str2DirectionType(settings.value("direction").value<QString>());
        io.isAlarm = settings.value("isAlarm").value<bool>();
        io.alarmText = settings.value("alarmText").value<QString>();
        io.invertLogic = settings.value("invertLogic").value<bool>();
        listDigitalIO.insert(io.name, io);
    }

    // qui controllo che ci siano almeno gli ingressi fondamentali
    if (!listDigitalIO.contains(DigitalPower.name))
        listDigitalIO.insert(DigitalPower.name, DigitalPower);

    if (!listDigitalIO.contains(DigitalCycle.name))
        listDigitalIO.insert(DigitalCycle.name, DigitalCycle);

    if (!listDigitalIO.contains(DigitalEnable.name))
        listDigitalIO.insert(DigitalEnable.name, DigitalEnable);

    if (!listDigitalIO.contains(DigitalLaserPower.name))
        listDigitalIO.insert(DigitalLaserPower.name, DigitalLaserPower);

    if (!listDigitalIO.contains(DigitalGreenLamp.name))
        listDigitalIO.insert(DigitalGreenLamp.name, DigitalGreenLamp);

    if (!listDigitalIO.contains(DigitalRedLamp.name))
        listDigitalIO.insert(DigitalRedLamp.name, DigitalRedLamp);

    settings.endArray();

}

void MachineDigitalIO::flush() const {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    settings.beginWriteArray(DIGITAL_ARRAY_NAME);

    int index = 0;
    for (auto io: listDigitalIO.values()) {
        settings.setArrayIndex(++index);
        settings.setValue("name", io.name);
        settings.setValue("channel", io.channel);
        settings.setValue("device", deviceType2Str(io.device));
        settings.setValue("direction", directionType2Str(io.direction));
        settings.setValue("isAlarm", io.isAlarm);
        settings.setValue("alarmText", io.alarmText);
        settings.setValue("invertLogic", io.invertLogic);
    }

    settings.endArray();

}
