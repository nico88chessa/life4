#include "CylinderDialog.hpp"
#include "ui_CylinderDialog.h"

#include <widgets/LineEditValidated.hpp>

CylinderDialog::CylinderDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CylinderDialog) {

    ui->setupUi(this);

//    QIntValidator& v = ui->circumference->getValidator();

    LineEditIntValidated* val = ui->circumference;
    new (&ui->circumference) LineEditIntValidated(10, 10);

    //v.setBottom(10);
    //
    //ui->length->getValidator().setBottom(-10);
    //
    //ui->startAt->setValidator(new QIntValidator(20,30));

    LineEditIntValidated test;
    QIntValidator prova;
    QIntValidator prova2;

}

CylinderDialog::~CylinderDialog() {
    delete ui;
}
