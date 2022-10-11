#ifndef LOGINDATAMANAGER_H
#define LOGINDATAMANAGER_H

#include <QMap>
#include <Qlist>
#include "user.h"
#include "parserfromtxt.h"
#include <QDir>
#include "validator.h"

class LoginDataManager
{
private:
    QList <User*> userList;
    User* currentUser;
    QString currentUserLogin;
    Validator* validator;

    ParserFromTxt* parser;
public:
    LoginDataManager();
    ~LoginDataManager();
   int checkLoginData(QString login, QString password);
   void setNewPassword(QString newPassword);
   QString getPasswordByLogin();

    Validator* getValidator();

   QList<User*> getUserList();

    User* getCurrentUser();

    const QString path = QDir::currentPath() + "/users.txt";

   bool addNewUser(QString login);
};

#endif // LOGINDATAMANAGER_H
