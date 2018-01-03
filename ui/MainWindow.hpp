#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <widgets/UnmovableMainWindow.hpp>
#include <configure.h>
#include <QFile>


namespace Ui {
class MainWindow;
}

static constexpr const char UI_BUTTON_FRAME_PROPERTY[] = "hidden";

class MainWindow : public life::UnmovableMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction* updateStyleSheetAction;

private slots:
    void hideMenu();
    void updateStyleSheet();

private:
    void buildMenuBar();

};

#endif // MAINWINDOW_HPP
