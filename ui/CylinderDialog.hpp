#ifndef CYLINDERDIALOG_HPP
#define CYLINDERDIALOG_HPP

#include <widgets/UnmovableDialog.hpp>

namespace Ui {
class CylinderDialog;
}

class CylinderDialog : public life::UnmovableDialog {
    Q_OBJECT

public:
    explicit CylinderDialog(QWidget *parent = 0);
    ~CylinderDialog();

private:
    Ui::CylinderDialog *ui;

};

#endif // CYLINDERDIALOG_HPP
