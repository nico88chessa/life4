#ifndef DIGITALIOPAGE_HPP
#define DIGITALIOPAGE_HPP

#include <QFrame>
#include <QListWidget>
#include <QTableWidget>
#include <QVector>

#include <core/logic/ParametersManager.hpp>


namespace Ui {
class DigitalIOPage;
}

class TableErrorWidget : public QTableWidget {
    Q_OBJECT
public:
    struct ConflictItem {
        life::DeviceKind device;
        int channel;
        QList<life::DigitalIO> digitalIO;
    };

public:
    explicit TableErrorWidget(QWidget *parent);

    void updateConflicts(const QList<ConflictItem>& items);

};


class DigitalIOPage : public QFrame {
    Q_OBJECT

private:
    Ui::DigitalIOPage *ui;

    std::shared_ptr<life::ParametersManager> parameterManager;
    QMap<QString, life::DigitalIO> digitalParameters;
    QString digitalIOSelectedKey;

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
