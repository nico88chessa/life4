#include "CylinderDialog.hpp"
#include "ui_CylinderDialog.h"

CylinderDialog::CylinderDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CylinderDialog) {

    ui->setupUi(this);
}

CylinderDialog::~CylinderDialog() {
    delete ui;
}
