#ifndef BINARYVALIDATOR_H
#define BINARYVALIDATOR_H

#include <QValidator>

class QValidator;

class BinaryValidator : public QValidator
{
public:
    BinaryValidator();
    State validate(QString & input, int & pos) const override;
};

#endif // BINARYVALIDATOR_H
