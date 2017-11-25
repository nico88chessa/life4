#include "SettingsPage.hpp"
#include "ui_SettingsPage.h"

SettingsPage::SettingsPage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingsPage) {

    ui->setupUi(this);

//    QLineEdit* lineEdit = new QLineEdit(this);
//    ui->verticalLayout->addWidget(lineEdit, Qt::AlignTop);
//    QLineEdit* lineEdit2 = new QLineEdit(this);
//    ui->verticalLayout->addWidget(lineEdit2, Qt::AlignTop);
//    QLineEdit* lineEdit3 = new QLineEdit(this);
//    ui->verticalLayout->addWidget(lineEdit3, Qt::AlignTop);
//    QLineEdit* lineEdit4 = new QLineEdit(this);
//    ui->verticalLayout->addWidget(lineEdit4, Qt::AlignTop);
//    QLineEdit* lineEdit5 = new QLineEdit(this);
//    ui->verticalLayout->addWidget(lineEdit5, Qt::AlignTop);
//    QLineEdit* lineEdit6 = new QLineEdit(this);
//    ui->verticalLayout->addWidget(lineEdit6, Qt::AlignTop);
//    QPushButton* button = new QPushButton(this);
//    button->setText("PROVA");
//    ui->verticalLayout->addWidget(button, Qt::AlignTop);
//    connect(button, &QPushButton::clicked, this, &SettingsPage::removeAllWidgets);

    ui->verticalLayout->addLayout(widgetFactory(life::machineparameters::MACHINE_ETH_INTERFACE_LAN));
    ui->verticalLayout->addLayout(widgetFactory(life::machineparameters::GUI_SPLASH_ENABLE));
    ui->verticalLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding));

}

SettingsPage::~SettingsPage() {
    delete ui;
}

void SettingsPage::removeAllWidgets() {
    QLayoutItem* item;
    while ((item = ui->verticalLayout->takeAt(0)) != nullptr) {
        delete item;
    }

}

void SettingsPage::updateSetting() {


    auto value = qobject_cast<QComboBox*>(sender());
    if (value) {

        qDebug() << this->sender();
    }
}

