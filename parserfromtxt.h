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
};

#endif // PARSERFROMTXT_H
