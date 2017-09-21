#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <widgets/UnmovableMainWindow.hpp>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public life::UnmovableMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void hideMenu();

};

#endif // MAINWINDOW_HPP
