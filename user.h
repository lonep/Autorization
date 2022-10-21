#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User(QString log, QString pas = "password", bool bl = false, bool admin = false, bool validator = false);

    QString getLogin();
    QString getPassword();
    bool getIsBlocked();
    bool getHasAdminRights();
    bool isValidatorActive();

    void setLogin(const QString login);
    bool setPassword(const QString password);
    void setIsBlocked(const bool state);
    void setHasAdminRights(const bool state);
    void setValidatorActive(const bool state);


private:
    QString login;
    QString password;
    bool isBlocked;
    bool hasAdminRights;
    bool validatorActive;
};

#endif // USER_H
