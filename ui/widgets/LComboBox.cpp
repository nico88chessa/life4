#include "LComboBox.hpp"

LComboBox::LComboBox(QWidget *parent) : QWidget(parent) {

    layout = new QVBoxLayout();
    layout->setMargin(0);

    combobox = new QComboBox();
    label = new QLabel();

    layout->addWidget(label);
    layout->addWidget(combobox);

    this->setLayout(layout);

    this->setFocusProxy(combobox);

    createSignalsAndConnections();
}

void LComboBox::createSignalsAndConnections() {

    connect(combobox, &QComboBox::editTextChanged, this, &LComboBox::editTextChanged);

    connect(combobox, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated),
            this, static_cast<void (LComboBox::*)(int)>(&LComboBox::activated));

    connect(combobox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::activated),
            this, static_cast<void (LComboBox::*)(const QString &)>(&LComboBox::activated));

    connect(combobox, static_cast<void (QComboBox::*)(int)>(&QComboBox::highlighted),
            this, static_cast<void (LComboBox::*)(int)>(&LComboBox::highlighted));

    connect(combobox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::highlighted),
            this, static_cast<void (LComboBox::*)(const QString &)>(&LComboBox::highlighted));

    connect(combobox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, static_cast<void (LComboBox::*)(int)>(&LComboBox::currentIndexChanged));

    connect(combobox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            this, static_cast<void (LComboBox::*)(const QString&)>(&LComboBox::currentIndexChanged));

    connect(combobox, &QComboBox::currentTextChanged, this, &LComboBox::currentTextChanged);
}

void LComboBox::init(const QString& text, const QStringList &list) {
    this->setLabelText(text);
    if (!list.isEmpty())
        this->addItems(list);
}

void LComboBox::setCurrentIndex(int index) {
    combobox->setCurrentIndex(index);
}

