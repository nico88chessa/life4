#ifndef INTLINEEDIT_HPP
#define INTLINEEDIT_HPP

#include <QLineEdit>
#include <QValidator>
#include <QStyle>
#include <limits>

static constexpr char QSS_INT_LINE_VALID_PROPERTY[] = "valid";

class IntLineEdit : public QLineEdit {
    Q_OBJECT

public:
    using Ptr = IntLineEdit *;
    using ConstPtr = const IntLineEdit *;

private:
    QIntValidator validator;

public:
    IntLineEdit(QWidget* parent = Q_NULLPTR);
    IntLineEdit(int _bottom, int _top, QWidget* parent = Q_NULLPTR);

    QIntValidator& getValidator();

private slots:
    void validate();

signals:
    void isValidSignal(bool);

};

#endif // INTLINEEDIT_HPP
