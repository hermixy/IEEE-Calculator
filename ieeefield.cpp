#include "ieeefield.h"
#include <QGridLayout>
#include <QPushButton>
#include "binaryvalidator.h"
#include <QLabel>

IEEEField::IEEEField(QWidget *parent) : QWidget(parent)
{
    value = 0.0f;

    QGridLayout * layout = new QGridLayout();

    BinaryValidator * validator = new BinaryValidator();

    QPushButton * fillOnesButton = new QPushButton("Wypelnij jedynkami", this);
    connect(fillOnesButton, SIGNAL(clicked()), this, SLOT(fillOnesClicked()));

    QPushButton * fillZeroesButton = new QPushButton("Wypelnij zerami", this);
    connect(fillZeroesButton, SIGNAL(clicked()), this, SLOT(fillZeroesClicked()));

    QLabel * signLab = new QLabel("Znak");
    QLabel * exponentLab = new QLabel("Wykladnik");
    QLabel * mantissLab = new QLabel("Mantysa");

    this->valueLabel = new QLabel(QString::number(value, 'g', 64), this);

    this->signField = new QLineEdit();
    this->signField->setFixedWidth(50);
    this->signField->setMaxLength(1);
    this->signField->setValidator(validator);
    this->signField->setAlignment(Qt::AlignCenter);
    this->signField->deselect();
    connect(this->signField, SIGNAL(textChanged(QString)), this, SLOT(signUpdate()));

    this->exponentField = new QLineEdit();
    this->exponentField->setFixedWidth(150);
    this->exponentField->setMaxLength(11);
    this->exponentField->setValidator(validator);
    this->exponentField->setAlignment(Qt::AlignCenter);
    this->exponentField->deselect();
    connect(this->exponentField, SIGNAL(textEdited(QString)), this, SLOT(updateValue()));

    this->mantissField = new QLineEdit();
    this->mantissField->setFixedWidth(600);
    this->mantissField->setMaxLength(52);
    this->mantissField->setValidator(validator);
    this->mantissField->setAlignment(Qt::AlignCenter);
    this->mantissField->deselect();
    connect(this->mantissField, SIGNAL(textEdited(QString)), this, SLOT(updateValue()));

    layout->addWidget(signLab, 0, 0, Qt::AlignCenter);
    layout->addWidget(exponentLab, 0, 1, Qt::AlignCenter);
    layout->addWidget(mantissLab, 0, 2, Qt::AlignCenter);

    layout->addWidget(signField, 1, 0);
    layout->addWidget(exponentField, 1, 1);
    layout->addWidget(mantissField, 1, 2);

    layout->addWidget(fillOnesButton, 1, 3);
    layout->addWidget(fillZeroesButton, 1, 4);

    layout->addWidget(this->valueLabel, 2, 0, 1, 3, Qt::AlignCenter);

    this->setLayout(layout);
}

IEEEField::~IEEEField()
{
    delete this->signField;
    delete this->exponentField;
    delete this->mantissField;

    this->signField = nullptr;
    this->exponentField = nullptr;
    this->mantissField = nullptr;
}

void IEEEField::SetFontSize(const unsigned int i)
{
    QFont font;
    font.setPointSize(i);

    this->signField->setFont(font);
    this->exponentField->setFont(font);
    this->mantissField->setFont(font);
}

void IEEEField::fillOnesClicked()
{
    QString mantisText = this->mantissField->text();
    for(int i = mantisText.length(); i < this->mantissField->maxLength(); i++)
    {
        mantisText[i] = 49;
    }
    this->mantissField->setText(mantisText);
}

void IEEEField::fillZeroesClicked()
{
    QString mantisText = this->mantissField->text();
    for(int i = mantisText.length(); i < this->mantissField->maxLength(); i++)
    {
        mantisText[i] = 48;
    }
    this->mantissField->setText(mantisText);
}

void IEEEField::updateValue()
{

}

void IEEEField::signUpdate()
{
    QString string = this->valueLabel->text();
    if(string.at(0) != '-' && this->signField->text() == "1")
    {
        string.insert(0, "-");
        return;
    }
    else if(this->signField->text() == "" || this->signField->text() == "0")
    {
        string.insert(0, "");
    }

    this->valueLabel->setText(string);
}

