#include "binaryvalidator.h"

BinaryValidator::BinaryValidator()
{

}

QValidator::State BinaryValidator::validate(QString & input, int & pos) const
{

    if(input.isEmpty())
    {
        return Acceptable;
    }
    else
    {
        if(pos == 0)
        {
            return Acceptable;
        }

        if(input.at(pos - 1) == 48 || input.at(pos - 1) == 49)
        {
            return Acceptable;
        }
        else
        {
            return Invalid;
        }
    }
}

