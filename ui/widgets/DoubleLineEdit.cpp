#include "DoubleLineEdit.hpp"

DoubleLineEdit::DoubleLineEdit(QWidget* parent)
    : DoubleLineEdit(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max(), default_decimal, parent) { }

DoubleLineEdit::DoubleLineEdit(int decimal, QWidget* parent)
    : DoubleLineEdit(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max(), decimal, parent) { }


QDoubleValidator& DoubleLineEdit::getValidator() {
    return validator;
}

DoubleLineEdit::DoubleLineEdit(double _bottom, double _top, int _decimal, QWidget* parent) {

    validator.setBottom(_bottom);
    validator.setTop(_top);
    validator.setDecimals(_decimal);

    connect(this, &QLineEdit::textChanged, this, &DoubleLineEdit::validate);

}

void DoubleLineEdit::validate() {

    int pos = 0;
    QString value = this->text();
    QValidator::State state = validator.validate(value, pos);

    switch(state) {
    case QValidator::Acceptable:
        this->setProperty(QSS_DOUBLE_LINE_VALID_PROPERTY, true);
        break;
    case QValidator::Intermediate:
    case QValidator::Invalid:
        this->setProperty(QSS_DOUBLE_LINE_VALID_PROPERTY, false);
        break;
    }

    this->style()->unpolish(this);
    this->style()->polish(this);

    emit isValidSignal(state == QValidator::Acceptable);
}
