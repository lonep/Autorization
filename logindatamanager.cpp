#include "logindatamanager.h"
#include "parserfromtxt.h"
#include <QDir>

LoginDataManager::LoginDataManager()
{
    parser = new ParserFromTxt();
    userList = parser->getUsersFromFile(path);

    validator = new Validator(this);
}

LoginDataManager::~LoginDataManager()
{

    delete validator;

    parser->writeUsersInFile(userList, path);
    foreach (auto it, userList)
    {
        delete it;
    }
}

int LoginDataManager::checkLoginData(QString login, QString password) // 2 - for admin, 1 - user, 0 - isn't correct
{
    for (auto it: userList)
    {
        if(it->getLogin() == login && it->getPassword() == password && !it->getIsBlocked())
        {
            currentUser = it;
            if (it->getHasAdminRights())
                return 2;
            else
                return 1;
        }
    }
    return 0;
}

void LoginDataManager::setNewPassword(QString newPassword)
{
    currentUser->setPassword(newPassword);
}

QString LoginDataManager::getPasswordByLogin()
{

}

Validator *LoginDataManager::getValidator()
{
    return validator;
}

QList<User*> LoginDataManager::getUserList()
{
    return userList;
}

User *LoginDataManager::getCurrentUser()
{
    return currentUser;
}

bool LoginDataManager::addNewUser(QString login)
{
    for (auto it: userList)
    {
        if (it->getLogin() == login)
            return false;
        else
        {
            userList.push_back(new User(login));
            return true;
        }
    }
}


