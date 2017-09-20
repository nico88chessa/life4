#ifndef UNMOVABLEMAINWINDOW_HPP
#define UNMOVABLEMAINWINDOW_HPP

#include <QMainWindow>

namespace life {

class UnmovableMainWindow : public QMainWindow {
public:
    using Ptr = UnmovableMainWindow *;
    using ConstPtr = const UnmovableMainWindow *;

private:
    QRect g;

public:
    explicit UnmovableMainWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags())
        : QMainWindow(parent, flags) {

        g = this->geometry();
    }

protected:

    virtual void moveEvent(QMoveEvent *event) {
        Q_UNUSED(event);
        this->setGeometry(g);
    }

};

}

#endif // UNMOVABLEMAINWINDOW_HPP
