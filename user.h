#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User(QString log, QString pas = "password", bool bl = false, bool admin = false);

    QString getLogin();
    QString getPassword();
    bool getIsBlocked();
    bool getHasAdminRights();

    void setLogin(const QString login);
    void setPassword(const QString password);
    void setIsBlocked(const bool state);
    void setHasAdminRights(const bool state);

private:
    QString login;
    QString password;
    bool isBlocked;
    bool hasAdminRights;
};

#endif // USER_H
