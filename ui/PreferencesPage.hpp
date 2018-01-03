#ifndef PREFERENCESPAGE_HPP
#define PREFERENCESPAGE_HPP


#include <logic/ParametersManager.hpp>

#include <QFrame>
#include <QMessageBox>

#include <memory>


namespace Ui {
class PreferencesPage;
}


class PreferencesPage : public QFrame {
    Q_OBJECT

public:
    explicit PreferencesPage(QWidget *parent = 0);
    ~PreferencesPage();

    void init();

public slots:
    void save();

private:
    Ui::PreferencesPage *ui;
    std::shared_ptr<life::ParametersManager> parameters;

    void setupGraphics();

    void createConnections();

    void model2View();

private slots:

};

#endif // PREFERENCESPAGE_HPP
