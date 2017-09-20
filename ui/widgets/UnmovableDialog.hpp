#ifndef UNMOVABLEDIALOG_HPP
#define UNMOVABLEDIALOG_HPP

#include <QDialog>

namespace life {

class UnmovableDialog : public QDialog {
public:
    using Ptr = UnmovableDialog *;
    using ConstPtr = const UnmovableDialog *;

private:
    QRect g;

public:
    explicit UnmovableDialog(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags())
        : QDialog(parent, f) {

        g = this->geometry();
    }

protected:

    virtual void moveEvent(QMoveEvent *event) {
        Q_UNUSED(event);
        this->setGeometry(g);
    }

};

}

#endif // UNMOVABLEDIALOG_HPP
