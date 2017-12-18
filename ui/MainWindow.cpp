#include "MainWindow.hpp"
#include <ui_MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : life::UnmovableMainWindow(parent, Qt::WindowFlags(Qt::FramelessWindowHint)),
      ui(new Ui::MainWindow) {

    ui->setupUi(this);

    connect(ui->hideMenuButton, &QPushButton::clicked, this, &MainWindow::hideMenu);

    QFile file(":/styles/style1.qss");
    if (!file.open(QFile::ReadOnly))
        return;
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::hideMenu() {

    if (ui->buttonFrame->maximumWidth() == 0)
        ui->buttonFrame->setMaximumWidth(200);
    else
        ui->buttonFrame->setMaximumWidth(0);
}

