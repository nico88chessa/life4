#ifndef LINEEDITVALIDATED_HPP
#define LINEEDITVALIDATED_HPP

#include <QLineEdit>
#include <QValidator>
#include <QStyle>
#include <limits>

static constexpr char QSS_VALID_PROPERTY[] = "valid";

class LineEditIntValidated : public QLineEdit {
    Q_OBJECT

public:
    using Ptr = LineEditIntValidated *;
    using ConstPtr = const LineEditIntValidated *;

private:
    QIntValidator validator;

public:
    LineEditIntValidated(QWidget* parent = Q_NULLPTR);
    LineEditIntValidated(int _bottom, int _top, QWidget* parent = Q_NULLPTR);

    QIntValidator& getValidator();

private slots:
    void validate();

signals:
    void isValidSignal(bool);

};



class LineEditDoubleValidated : public QLineEdit {
    Q_OBJECT

public:
    using Ptr = LineEditDoubleValidated *;
    using ConstPtr = const LineEditDoubleValidated *;

protected:
    static constexpr int default_decimal = 3;

private:
    QDoubleValidator validator;

public:
    LineEditDoubleValidated(double _bottom, double _top, int _decimal, QWidget* parent = Q_NULLPTR);
    LineEditDoubleValidated(int decimal = default_decimal, QWidget* parent = Q_NULLPTR);
    LineEditDoubleValidated(QWidget* parent = Q_NULLPTR);

    QDoubleValidator& getValidator();

private slots:
    void validate();

signals:
    void isValidSignal(bool);

};

#endif // LINEEDITINTVALIDATED_HPP
