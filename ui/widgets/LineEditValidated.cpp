#include "LineEditValidated.hpp"

/* LineEditIntValidated */

QIntValidator& LineEditIntValidated::getValidator() {
    return validator;
}

LineEditIntValidated::LineEditIntValidated(QWidget* parent)
    : LineEditIntValidated(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), parent) { }

LineEditIntValidated::LineEditIntValidated(int _bottom, int _top, QWidget* parent) {

    validator.setBottom(_bottom);
    validator.setTop(_top);

    connect(this, &QLineEdit::textChanged, this, &LineEditIntValidated::validate);

}

void LineEditIntValidated::validate() {

    int pos = 0;
    QString value = this->text();
    QValidator::State state = validator.validate(value, pos);

    switch(state) {
    case QValidator::Acceptable:
        this->setProperty(QSS_VALID_PROPERTY, true);
        break;
    case QValidator::Intermediate:
    case QValidator::Invalid:
        this->setProperty(QSS_VALID_PROPERTY, false);
        break;
    }

    this->style()->unpolish(this);
    this->style()->polish(this);

    emit isValidSignal(state == QValidator::Acceptable);
}


/* LineEditDoubleValidated */


LineEditDoubleValidated::LineEditDoubleValidated(QWidget* parent)
    : LineEditDoubleValidated(std::numeric_limits<double>::min(), std::numeric_limits<double>::max(), default_decimal, parent) { }

LineEditDoubleValidated::LineEditDoubleValidated(int decimal, QWidget* parent)
    : LineEditDoubleValidated(std::numeric_limits<double>::min(), std::numeric_limits<double>::max(), decimal, parent) { }


QDoubleValidator& LineEditDoubleValidated::getValidator() {
    return validator;
}

LineEditDoubleValidated::LineEditDoubleValidated(double _bottom, double _top, int _decimal, QWidget* parent) {

    validator.setBottom(_bottom);
    validator.setTop(_top);
    validator.setDecimals(_decimal);

    connect(this, &QLineEdit::textChanged, this, &LineEditDoubleValidated::validate);

}

void LineEditDoubleValidated::validate() {

    int pos = 0;
    QString value = this->text();
    QValidator::State state = validator.validate(value, pos);

    switch(state) {
    case QValidator::Acceptable:
        this->setProperty(QSS_VALID_PROPERTY, true);
        break;
    case QValidator::Intermediate:
    case QValidator::Invalid:
        this->setProperty(QSS_VALID_PROPERTY, false);
        break;
    }

    this->style()->unpolish(this);
    this->style()->polish(this);

    emit isValidSignal(state == QValidator::Acceptable);
}
