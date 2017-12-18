#ifndef DOUBLELINEEDIT_HPP
#define DOUBLELINEEDIT_HPP

#include <QLineEdit>
#include <QValidator>
#include <QStyle>
#include <limits>

static constexpr char QSS_DOUBLE_LINE_VALID_PROPERTY[] = "valid";

class DoubleLineEdit : public QLineEdit {
    Q_OBJECT

public:
    using Ptr = DoubleLineEdit *;
    using ConstPtr = const DoubleLineEdit *;

protected:
    static constexpr int default_decimal = 3;

private:
    QDoubleValidator validator;

public:
    DoubleLineEdit(double _bottom, double _top, int _decimal, QWidget* parent = Q_NULLPTR);
    DoubleLineEdit(int decimal = default_decimal, QWidget* parent = Q_NULLPTR);
    DoubleLineEdit(QWidget* parent = Q_NULLPTR);

    QDoubleValidator& getValidator();

private slots:
    void validate();

signals:
    void isValidSignal(bool);

};

#endif // DOUBLELINEEDIT_HPP
