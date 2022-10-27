#include "parserfromtxt.h"
#include "user.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCryptographicHash>
#include <openssl/rc4.h>
#include <openssl/md5.h>
#include <QByteArray>
#include <QMessageBox>

#include <QProcess>



ParserFromTxt::ParserFromTxt()
{
    QString p = "kopibara1";
    password = QCryptographicHash::hash(p.toLatin1(),QCryptographicHash::Md5).toHex();
    setlocale(LC_ALL, "Russian");
}

QList<User*> ParserFromTxt::getUsersFromFile(QString path)
{
    QList<User*> users;
    QFile inputFile(path);

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       QString all =  inputFile.readAll();

       for (auto it: all.split("mc", Qt::SkipEmptyParts))
       {
          QString res = decryptLine(it, password);
          auto usr = res.split(" ", Qt::SkipEmptyParts);
          try
          {
              users.push_back(new User(usr[0], usr[1], usr[2].toInt(), usr[3].toInt(), usr[4].toInt()));
          } catch (...)
          {
              QMessageBox error;
              error.setText("File corrupted");
              error.exec();
          }
       }
       inputFile.close();
    }
    qDebug() << QCryptographicHash::Md5;

    foreach(auto x, users)
        qDebug() << x->getLogin();

    return users;
}

//QList<User*> ParserFromTxt::getUsersFromFile(QString path)
//{
//    QList<User*> users;
//    QFile inputFile(path);

//    if (inputFile.open(QIODevice::ReadOnly))
//    {
//       QTextStream in(&inputFile);
//       while (!in.atEnd())
//       {
//          QString line = in.readLine();
//          auto usr = line.split(" ", Qt::SkipEmptyParts);
//          users.push_back(new User(usr[0], usr[1], usr[2].toInt(), usr[3].toInt(), usr[4].toInt()));
//       }
//       inputFile.close();
//    }
//    qDebug() << QCryptographicHash::Md5;

//    foreach(auto x, users)
//        qDebug() << x->getLogin();

//    return users;
//}



void ParserFromTxt::writeUsersInFile(QList<User *> users, QString path)
{
    QFile inputFile(path);
    QFile file(path);

    if ( file.open(QIODevice::ReadWrite | QIODevice::Truncate) )
    {
        QTextStream stream( &file );
        QString str;


        foreach (auto it, users)
        {
              str = it->getLogin() + " "
                  + it->getPassword() + " "
                  + QString::number(it->getIsBlocked()) + " "
                  + QString::number(it->getHasAdminRights()) + " "
                  + QString::number(it->isValidatorActive());


                str = encryptLine(str, password);
                stream << str << "mc";
        }
    }

}

QByteArray ParserFromTxt::encryptData(const QByteArray password, const QByteArray &data)
{
    RC4_KEY key;

    unsigned char md_hash[MD5_DIGEST_LENGTH];
    unsigned char* encryptedData;

    MD5((const unsigned char*)password.constData(), password.size(), md_hash);
    RC4_set_key(&key, MD5_DIGEST_LENGTH, md_hash);
    RC4(&key, data.size(), (const unsigned char*) data.constData(), encryptedData);



    return QByteArray(reinterpret_cast<char*>(encryptedData), data.size());
}

QString ParserFromTxt::encryptLine(QString data, QString key)
{
    QString program = "C:/Users/lonep/Downloads/openssl-aes-cipher-master2/easy-encryption/a.exe";

    QStringList arguments;
    arguments << data<< key << "0";

    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);

    myProcess->waitForFinished(-1);
    QString res = myProcess->readAllStandardOutput();
    res.chop(2);

    delete myProcess;
    return res;
}

QString ParserFromTxt::decryptLine(QString data, QString key)
{
    QString program = "C:/Users/lonep/Downloads/openssl-aes-cipher-master2/easy-encryption/a.exe";

    QStringList arguments;
    arguments << data<< key << "1";

    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);

    myProcess->waitForFinished(-1);
    QString res = myProcess->readAllStandardOutput();
    res.chop(2);

    delete myProcess;
    return res;
}

QByteArray ParserFromTxt::decryptData(const QByteArray password, const QByteArray &data)
{
    RC4_KEY key;

    unsigned char md_hash[MD5_DIGEST_LENGTH];
    unsigned char* decryptedData;

    MD5((const unsigned char*)password.constData(), password.size(), md_hash);
    RC4_set_key(&key, MD5_DIGEST_LENGTH, md_hash);
    qDebug() << data.size();
    RC4(&key, data.size(), (const unsigned char*) data.constData(), decryptedData);



    return QByteArray(reinterpret_cast<char*>(decryptedData), data.size());
}
