#include "CylinderDialog.hpp"
#include "ui_CylinderDialog.h"

CylinderDialog::CylinderDialog(QWidget *parent)
    : UnmovableDialog(parent, Qt::WindowFlags(Qt::FramelessWindowHint)), ui(new Ui::CylinderDialog) {

    ui->setupUi(this);

    QIntValidator& v = ui->circumference->getValidator();

    v.setRange(0, 10);

}

CylinderDialog::~CylinderDialog() {
    delete ui;
}
