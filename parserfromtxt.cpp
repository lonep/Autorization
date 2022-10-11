#include "parserfromtxt.h"
#include "User.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

ParserFromTxt::ParserFromTxt()
{

}

QList<User*> ParserFromTxt::getUsersFromFile(QString path)
{
    QList<User*> users;
    QFile inputFile(path);

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          auto usr = line.split(" ", Qt::SkipEmptyParts);
          users.push_back(new User(usr[0], usr[1], usr[2].toInt(), usr[3].toInt()));
       }
       inputFile.close();
    }

    foreach(auto x, users)
        qDebug() << x->getLogin();

    return users;
}

void ParserFromTxt::writeUsersInFile(QList<User *> users, QString path)
{
    QFile inputFile(path);

    QFile file(path);
    if ( file.open(QIODevice::ReadWrite | QIODevice::Truncate) )
    {
        QTextStream stream( &file );

        foreach (auto it, users)
        {
            stream << it->getLogin() << " " << it->getPassword() << " "
                   << it->getIsBlocked() << " " << it->getHasAdminRights() << "\n";
        }
    }
}
