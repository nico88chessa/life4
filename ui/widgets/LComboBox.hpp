#ifndef LCOMBOBOX_HPP
#define LCOMBOBOX_HPP

#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>

class LComboBox : public QWidget {
    Q_OBJECT

private:
    QVBoxLayout* layout;
    QLabel* label;
    QComboBox* combobox;

signals:
    void editTextChanged(const QString &);
    void activated(int index);
    void activated(const QString &);
    void highlighted(int index);
    void highlighted(const QString &);
    void currentIndexChanged(int index);
    void currentIndexChanged(const QString &);
    void currentTextChanged(const QString &);

public:
    explicit LComboBox(QWidget *parent = nullptr);

private:
    void createSignalsAndConnections();

public:
    void init(const QString& text, const QStringList &list);

    inline QString getLabelText() const {
        return label->text();
    }

    inline void setLabelText(const QString &text) {
        label->setText(text);
    }

    inline void addItem(const QString &text, const QVariant &userData = QVariant()) {
        combobox->addItem(text, userData);
    }

    inline void addItems(const QStringList &texts) {
        combobox->addItems(texts);
    }

public slots:
    void setCurrentIndex(int index);

};


#endif // LCOMBOBOX_HPP
