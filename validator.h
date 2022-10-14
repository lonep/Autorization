#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QRegularExpression>
class LoginDataManager;
class Validator : public QRegularExpression
{
public:
    Validator();
    Validator(LoginDataManager *dataManager);
    QRegularExpression passwordExp;
    bool validatePassword(QString password);
private:
    LoginDataManager *dataManager;
//    validatePa
};

#endif // VALIDATOR_H
