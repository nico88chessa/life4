#include "MainWindow.hpp"
#include <ui_MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : life::UnmovableMainWindow(parent, Qt::WindowFlags(Qt::FramelessWindowHint)),
      ui(new Ui::MainWindow) {

    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::click1);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::click2);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::click1() {
    QFile file(":/styles/test1.qss");
    if (!file.open(QFile::ReadOnly))
        return;
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);

}

void MainWindow::click2() {
    QFile file(":/styles/test2.qss");
    if (!file.open(QFile::ReadOnly))
        return;
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);

}
