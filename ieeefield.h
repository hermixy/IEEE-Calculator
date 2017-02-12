#ifndef IEEEFIELD_H
#define IEEEFIELD_H

#include <QLineEdit>
#include <QWidget>
#include <QLabel>

class IEEEField : public QWidget
{
    Q_OBJECT
public:
    explicit IEEEField(QWidget *parent = 0);
    ~IEEEField();
    void SetFontSize(const unsigned int i);

signals:


private slots:
    void fillZeroesClicked();
    void fillOnesClicked();
    void updateValue();
    void signUpdate();
    int XD();

private:
    QLineEdit * signField;
    QLineEdit * exponentField;
    QLineEdit * mantissField;
    QLabel * valueLabel;
    double value;
};

#endif // IEEEFIELD_H
