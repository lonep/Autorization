#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QRegularExpression>

class Validator : public QRegularExpression
{
public:
    Validator();
    QRegularExpression passwordExp;
    bool validatePassword(QString password);

//    validatePa
};

#endif // VALIDATOR_H
