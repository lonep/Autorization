#include "validator.h"
#include <QRegularExpressionValidator>
#include "logindatamanager.h"

Validator::Validator()
{
    passwordExp.setPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*[а-я])(?=.*[А-Я])(?=.*[0-9])(?=.*\d)[a-zA-Zа-яА-Я0-9\d]{5,}$");
    //    /(?=.*[0-9])(?=.*[!@#$%^&*])(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z!@#$%^&*]{6,}/g
}

Validator::Validator(LoginDataManager *dataManager)
{
    this->dataManager = dataManager;
}

bool Validator::validatePassword(QString password)
{
    if (!dataManager->getCurrentUser()->isValidatorActive())
        return true;

    QRegularExpressionMatch match = passwordExp.match(password);
    if (!match.hasMatch())
        return true;
    else return false;
}
