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

private:
    Ui::DigitalIOPage *ui;

    std::shared_ptr<life::ParametersManager> parameterManager;
    QMap<QString, std::shared_ptr<life::DigitalIO> > digitalParameters;
    life::DigitalIO digitalIOSelected;

public:
    explicit DigitalIOPage(QWidget *parent = 0);
    ~DigitalIOPage();

    void init(const std::shared_ptr<life::ParametersManager>& parameterManager);

public slots:
    void reset();

    bool save();

private:
    void setupGraphics();

    void createConnections();

    void model2View();

    void blockIoDetailsSignals(bool value);

    bool validate();

private slots:
    void IOItemListActivated(QListWidgetItem* item, QListWidgetItem *previous);

};

#endif // DIGITALIOPAGE_HPP
