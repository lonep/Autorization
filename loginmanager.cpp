#include "loginmanager.h"
#include "logindatamanager.h"
#include "QDebug"

LoginManager::LoginManager()
{
    loginMistake = 0;
}

LoginManager::~LoginManager()
{
    delete dataManager;
}

const bool LoginManager::login(QString login, QString password)
{
    if (dataManager->checkLoginData(login, password) == 2 && loginMistake < 3)
    {
        loginMistake = 0;
        return true;
    }

    if (dataManager->checkLoginData(login, password) == 1 && loginMistake < 3)
    {
        loginMistake = 0;
        return true;
    }

    if (dataManager->checkLoginData(login, password) == 0 && loginMistake < 3)
    {
        qDebug() << "Mistake";
        loginMistake += 1;
        return false;
    }

}

const int LoginManager::gerLoginMistake()
{
    return loginMistake;
}

LoginDataManager* LoginManager::getLoginDataManager()
{
 return dataManager;
}
