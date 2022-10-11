#include "user.h"


User::User(QString log, QString pas, bool bl, bool admin)
    : login{log}, password{pas}, isBlocked{bl}, hasAdminRights{admin}

{

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

void User::setLogin(const QString login)
{
    this->login = login;
}

void User::setPassword(const QString password)
{
    this->password = password;
}

void User::setIsBlocked(const bool state)
{
    this->isBlocked = state;
}

void User::setHasAdminRights(const bool state)
{
    this->hasAdminRights = state;
}
