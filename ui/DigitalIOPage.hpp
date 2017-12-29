#ifndef DIGITALIOPAGE_HPP
#define DIGITALIOPAGE_HPP

#include <QFrame>
#include <QListWidget>

#include <core/logic/ParametersManager.hpp>


namespace Ui {
class DigitalIOPage;
}

class DigitalIOPage : public QFrame
{
    Q_OBJECT

public:
    explicit DigitalIOPage(QWidget *parent = 0);
    ~DigitalIOPage();

private:
    Ui::DigitalIOPage *ui;
    life::ParametersManager parameterManager;
    QMap<QString, std::shared_ptr<life::DigitalIO> > digitalParameters;

    life::DigitalIO digitalIOSelected;

private slots:
    void IOItemListActivated(QListWidgetItem* item, QListWidgetItem *previous);

private:
    void manageSignalsAndSlots();

    void setupGraphics();

    void model2View();

    void blockIoDetailsSignals(bool value);

};

#endif // DIGITALIOPAGE_HPP
