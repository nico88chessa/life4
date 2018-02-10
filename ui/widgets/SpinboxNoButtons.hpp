#ifndef SPINBOXNOBUTTONS_HPP
#define SPINBOXNOBUTTONS_HPP

#include <QSpinBox>

namespace life {

class SpinboxNoButtons : public QSpinBox {
    Q_OBJECT

public:
    explicit SpinboxNoButtons(QWidget *parent = Q_NULLPTR);

    ~SpinboxNoButtons();
};

}

#endif // SPINBOXNOBUTTONS_HPP
