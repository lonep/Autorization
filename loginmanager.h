#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include "logindatamanager.h"
#include <QObject>

class LoginManager : public QObject
{
    Q_OBJECT
public:
    LoginManager();
    ~LoginManager();

    LoginDataManager *dataManager = new LoginDataManager();

    LoginDataManager* getLoginDataManager();

    const int gerLoginMistake();
private:
    int loginMistake;

public slots:
    const bool login(QString login, QString password);
};

#endif // LOGINMANAGER_H
