#include "IntLineEdit.hpp"

IntLineEdit::IntLineEdit(QWidget* parent)
    : IntLineEdit(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), parent) { }

IntLineEdit::IntLineEdit(int _bottom, int _top, QWidget* parent) {

    validator.setBottom(_bottom);
    validator.setTop(_top);

    connect(this, &QLineEdit::textChanged, this, &IntLineEdit::validate);

}

QIntValidator& IntLineEdit::getValidator() {
    return validator;
}

void IntLineEdit::validate() {

    int pos = 0;
    QString value = this->text();
    QValidator::State state = validator.validate(value, pos);

    switch(state) {
    case QValidator::Acceptable:
        this->setProperty(QSS_INT_LINE_VALID_PROPERTY, true);
        break;
    case QValidator::Intermediate:
    case QValidator::Invalid:
        this->setProperty(QSS_INT_LINE_VALID_PROPERTY, false);
        break;
    }

    this->style()->unpolish(this);
    this->style()->polish(this);

    emit isValidSignal(state == QValidator::Acceptable);
}
