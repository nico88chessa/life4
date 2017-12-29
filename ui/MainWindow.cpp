#include "MainWindow.hpp"
#include <ui_MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : life::UnmovableMainWindow(parent, Qt::WindowFlags(Qt::FramelessWindowHint)),
      ui(new Ui::MainWindow) {

    ui->setupUi(this);

    this->buildMenuBar();

    connect(ui->hideMenuButton, &QPushButton::clicked, this, &MainWindow::hideMenu);

    QFile file(QString(life::PROJECT_QSS_PATH)+"/style1.qss");
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

void MainWindow::updateStyleSheet() {

    QFile file(QString(life::PROJECT_QSS_PATH)+"/style1.qss");
    if (!file.open(QFile::ReadOnly))
        return;
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);
}

void MainWindow::buildMenuBar() {

    updateStyleSheetAction = new QAction("updateAction");
    connect(updateStyleSheetAction, &QAction::triggered, this, &MainWindow::updateStyleSheet);
    this->menuBar()->addAction(updateStyleSheetAction);

}

