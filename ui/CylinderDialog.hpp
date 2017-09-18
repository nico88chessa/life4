#ifndef CYLINDERDIALOG_HPP
#define CYLINDERDIALOG_HPP

#include <QDialog>

namespace Ui {
class CylinderDialog;
}

class CylinderDialog : public QDialog {
    Q_OBJECT

public:
    explicit CylinderDialog(QWidget *parent = 0);
    ~CylinderDialog();

private:
    Ui::CylinderDialog *ui;

};

#endif // CYLINDERDIALOG_HPP
