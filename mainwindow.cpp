#include "mainwindow.h"
#include <QGridLayout>
#include "ieeefield.h"
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget * viewport = new QWidget(this);
    this->setCentralWidget(viewport);

    QGridLayout * layout = new QGridLayout();
    viewport->setLayout(layout);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    IEEEField * firstNumberLabel = new IEEEField(viewport);
    firstNumberLabel->SetFontSize(14);

    IEEEField * secondNumberLabel = new IEEEField(viewport);
    secondNumberLabel->SetFontSize(14);

    layout->addWidget(firstNumberLabel, 0, 0);
    layout->addWidget(secondNumberLabel, 1, 0);

    this->setLayout(layout);
    this->setWindowTitle("IEEE Calculator");
    this->window()->setFixedHeight(768);
}

MainWindow::~MainWindow()
{

}
