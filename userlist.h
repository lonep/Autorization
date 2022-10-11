#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>
#include "user.h"
namespace Ui {
class userList;
}

class userList : public QDialog
{
    Q_OBJECT
enum states
{
    adminRights,
    blocked
};

public:
    explicit userList(QWidget *parent = nullptr, QList <User*> users = {});
    ~userList();
    void setUserList(QList <User*> users);
private:
    Ui::userList *ui;
    QList <User*> users;

void changeState(int state, const QString &login);
};

#endif // USERLIST_H
