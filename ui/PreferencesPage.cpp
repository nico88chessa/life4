#include "PreferencesPage.hpp"
#include "ui_PreferencesPage.h"

using namespace life;

PreferencesPage::PreferencesPage(QWidget *parent) :
    QFrame(parent), ui(new Ui::PreferencesPage) {

    ui->setupUi(this);

    init();
}

PreferencesPage::~PreferencesPage() {
    delete ui;
}

void PreferencesPage::init() {

    parameters = std::make_shared<ParametersManager>();

    this->setupGraphics();

    this->createConnections();

    this->model2View();

}

void PreferencesPage::save() {

    if (!ui->settingsFrame->save()) {
        QMessageBox msgBox;
        msgBox.setText(tr("Some wrong parameters have been set: check paramaters page"));
        msgBox.setStandardButtons(QMessageBox::Abort);
        msgBox.setStyleSheet("background-color: rgb(0, 200, 0);");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }

    if (!ui->digitalIOFrame->save()) {
        QMessageBox msgBox;
        msgBox.setText(tr("Some wrong digital IO have been set: check digital IO page"));
        msgBox.setStandardButtons(QMessageBox::Abort);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }

    this->parameters->flush();
}

void PreferencesPage::setupGraphics() {

    ui->settingsFrame->init(parameters);
    ui->digitalIOFrame->init(parameters);

}

void PreferencesPage::createConnections() {

    connect(ui->resetButton, &QPushButton::clicked, ui->settingsFrame, &SettingsPage::reset);
    connect(ui->resetButton, &QPushButton::clicked, ui->digitalIOFrame, &DigitalIOPage::reset);

    connect(ui->saveButton, &QPushButton::clicked, this, &PreferencesPage::save);

}

void PreferencesPage::model2View() {

}
