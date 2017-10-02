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


static constexpr char DIGITAL_PARAMETER_NAME[] = "Name";
static constexpr char DIGITAL_PARAMETER_CHANNEL[] = "Channel";
static constexpr char DIGITAL_PARAMETER_DEVICE[] = "Device";
static constexpr char DIGITAL_PARAMETER_DIRECTION[] = "Direction";
static constexpr char DIGITAL_PARAMETER_ISALARM[] = "IsAlarm";
static constexpr char DIGITAL_PARAMETER_ALARMTEXT[] = "AlarmText";
static constexpr char DIGITAL_PARAMETER_INVERTLOGIC[] = "InvertLogic";

MachineDigitalIO::MachineDigitalIO() {
    load();
}

void MachineDigitalIO::load() {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

    int size = settings.beginReadArray(DIGITAL_ARRAY_NAME);
    for (int i=0; i<size; ++i) {
        settings.setArrayIndex(i);
        DigitalIO io;
        io.name = settings.value(DIGITAL_PARAMETER_NAME).value<QString>();
        io.channel = settings.value(DIGITAL_PARAMETER_CHANNEL).value<quint32>();
        io.device = str2DeviceType(settings.value(DIGITAL_PARAMETER_DEVICE).value<QString>());
        io.direction = str2DirectionType(settings.value(DIGITAL_PARAMETER_DIRECTION).value<QString>());
        io.isAlarm = settings.value(DIGITAL_PARAMETER_ISALARM).value<bool>();
        io.alarmText = settings.value(DIGITAL_PARAMETER_ALARMTEXT).value<QString>();
        io.invertLogic = settings.value(DIGITAL_PARAMETER_INVERTLOGIC).value<bool>();
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
        settings.setValue(DIGITAL_PARAMETER_NAME, io.name);
        settings.setValue(DIGITAL_PARAMETER_CHANNEL, io.channel);
        settings.setValue(DIGITAL_PARAMETER_DEVICE, deviceType2Str(io.device));
        settings.setValue(DIGITAL_PARAMETER_DIRECTION, directionType2Str(io.direction));
        settings.setValue(DIGITAL_PARAMETER_ISALARM, io.isAlarm);
        settings.setValue(DIGITAL_PARAMETER_ALARMTEXT, io.alarmText);
        settings.setValue(DIGITAL_PARAMETER_INVERTLOGIC, io.invertLogic);
    }

    settings.endArray();

}
