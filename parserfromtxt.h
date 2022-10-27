#ifndef PARSERFROMTXT_H
#define PARSERFROMTXT_H
#include <QList>
class User;
class ParserFromTxt
{
public:
    ParserFromTxt();

    QList<User*> getUsersFromFile(QString path);
    void writeUsersInFile(QList<User*> users, QString path);
    QByteArray decryptData(const QByteArray password, const QByteArray &data);
    QByteArray encryptData(const QByteArray password, const QByteArray &data);

    QString encryptLine(QString data, QString key);
    QString decryptLine(QString data, QString key);

private:
    QString password;
};

#endif // PARSERFROMTXT_H
