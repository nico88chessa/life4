#include "SpinboxNoButtons.hpp"

life::SpinboxNoButtons::SpinboxNoButtons(QWidget *parent) : QSpinBox(parent) {
    this->setButtonSymbols(QSpinBox::NoButtons);
}

life::SpinboxNoButtons::~SpinboxNoButtons() { }
