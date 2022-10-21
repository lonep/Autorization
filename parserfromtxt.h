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

private:

};

#endif // PARSERFROMTXT_H
