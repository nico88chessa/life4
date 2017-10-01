#include "AnalogicIO.hpp"

using namespace life;

static constexpr char ANALOGIC_ARRAY_NAME[] = "AnalogicIO";

MachineAnalogicIO::MachineAnalogicIO() {
    load();
}

void MachineAnalogicIO::load() {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);
}

void MachineAnalogicIO::flush() const {

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, life::ORGANIZATION, life::APPLICATION_NAME);

}
