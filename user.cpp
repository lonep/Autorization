#include "user.h"
#include <QDebug>
#include <QCryptographicHash>

User::User(QString log, QString pas, bool bl, bool admin, bool validator)
    : login{log}, password{pas}, isBlocked{bl}, hasAdminRights{admin}, validatorActive{validator}

{
    qDebug() << isValidatorActive();
}

QString User::getLogin()
{
    return login;
}

QString User::getPassword()
{
    return password;
}

bool User::getIsBlocked()
{
    return isBlocked;
}

bool User::getHasAdminRights()
{
    return hasAdminRights;
}

bool User::isValidatorActive()
{
    return validatorActive;
}

void User::setLogin(const QString login)
{

    this->login = login;

}

bool User::setPassword(const QString password)
{

    this->password = password;
    return true;
}

void User::setIsBlocked(const bool state)
{
    this->isBlocked = state;
}

void User::setHasAdminRights(const bool state)
{
    this->hasAdminRights = state;
}

void User::setValidatorActive(const bool state)
{
    validatorActive = state;
}
