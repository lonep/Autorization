#include "userlist.h"
#include "ui_userlist.h"

userList::userList(QWidget *parent, QList <User*> users) :
    QDialog(parent),
    ui(new Ui::userList)
{
    ui->setupUi(this);
    this->users = users;

    for (auto &it: users)
        ui->listWidget->addItem(it->getLogin());



    connect(ui->listWidget, QListWidget::itemPressed, this, [this, users]()
    {
        foreach (auto it, users)
        {
            if (it->getLogin() == ui->listWidget->currentItem()->text())
            {
                ui->adminRights->setCheckState(it->getHasAdminRights() ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
                ui->userBlock->setCheckState(it->getIsBlocked() ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
                ui->validation->setCheckState(it->isValidatorActive() ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
                break;
            }
        }

    });


    connect(ui->adminRights, QCheckBox::clicked, this, [this]()
    {
        changeState(states::adminRights, ui->listWidget->currentItem()->text());

    });

    connect(ui->userBlock, QCheckBox::clicked, this, [this]()
    {
        changeState(states::blocked, ui->listWidget->currentItem()->text());
    });

    connect(ui->validation, QCheckBox::clicked, this, [this]()
    {
        changeState(states::validation, ui->listWidget->currentItem()->text());
    });
}

userList::~userList()
{
    delete ui;
}

void    userList::setUserList(QList <User*> users)
{
    this->users = users;
}

void userList::changeState(int state, const QString &login)
{
    if (state == states::adminRights)
    {
        foreach (auto it, users)
        {
            if (login == it->getLogin())
            {
                it->setHasAdminRights(!it->getHasAdminRights());
                qDebug() << it->getHasAdminRights();
                break;
            }
        }
    }

    if (state == states::blocked)
    {
        foreach (auto it, users)
        {
            if (login == it->getLogin())
            {
                it->setIsBlocked(!it->getIsBlocked());

                break;
            }
        }
    }

    if (state == states::validation)
    {
        foreach (auto it, users)
        {
            if (login == it->getLogin())
            {
                it->setValidatorActive(!it->isValidatorActive());

                break;
            }
        }
    }

}


