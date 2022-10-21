#include "panelwindow.h"
#include "logindatamanager.h"
#include "ui_panelwindow.h"
#include "changepassworddialog.h"
#include "newuserdialog.h"
#include "userlist.h"
#include "newpassworddialog.h"
#include "user.h"
#include <QMessageBox>

PanelWindow::PanelWindow(QWidget *parent, LoginDataManager* dataManager) :
    QWidget(parent),
    ui(new Ui::panelWindow)
{
    ui->setupUi(this);
    ui->label->setVisible(false);

    this->dataManager = dataManager;

    connect(ui->changePassword, QPushButton::clicked, this, [this, dataManager]()
    {


       QString newPassword = showChangePasswordDialog(dataManager->getCurrentUser()->getPassword());

       if(dataManager->getValidator()->validatePassword(newPassword))
           dataManager->getCurrentUser()->setPassword(newPassword);
       else
       {
           QMessageBox error;
           error.setText("Incorrect password. Password should contains only english, russian alphabet or numbers");
           error.exec();
       }
    });

    if (!dataManager->getCurrentUser()->getHasAdminRights())
    {
        ui->addNewUser->setVisible(false);
        ui->userView->setVisible(false);
    }
    else
    {
        ui->addNewUser->setVisible(true);
        ui->userView->setVisible(true);
    }

    connect(ui->addNewUser, QPushButton::clicked, this, [this, dataManager]()
    {
        QString newUserLogin = showNewUserDialog();

        if (newUserLogin != "")
        {
            if (dataManager->addNewUser(newUserLogin))
            {
//                ui->label->setVisible(false);
                QMessageBox password;
                password.setText("Temporary password is: password");
                password.exec();
            }
            else
            {
//                ui->label->setVisible(true);
                QMessageBox error;;
                error.setText("This login already exist");
                error.exec();
            }
        }

    });

    connect(ui->userView, QPushButton::clicked, this, [this, dataManager]()
    {
        showUserViewDialog(dataManager->getUserList());

    });

    if (dataManager->getCurrentUser()->getPassword() == "password")
    {
        this->isClose = true;

        QString newPassword = showChangePasswordDialog(dataManager->getCurrentUser()->getPassword());

        if(dataManager->getValidator()->validatePassword(newPassword))
        {
            dataManager->getCurrentUser()->setPassword(newPassword);
            isNewUser = true;
        }
        else
        {
            QMessageBox error;
            error.setText("Incorrect password. Password should contains only english, russian alphabet or numbers");
            error.exec();
        }

    }

    if (this->isClose)
        delete ui;
}

PanelWindow::~PanelWindow()
{
    delete ui;
}

QString PanelWindow::showChangePasswordDialog(QString oldPassword)
{
    ChangePasswordDialog changePasswordDialog(dataManager->getValidator());

    changePasswordDialog.setOldPassword(oldPassword);
    changePasswordDialog.setModal(true);
    changePasswordDialog.exec();

    qDebug() << "NEW password is " << changePasswordDialog.getNewPassword();
    return changePasswordDialog.getNewPassword() == "" ? oldPassword : changePasswordDialog.getNewPassword();
}

QString PanelWindow::showNewUserDialog()
{
    newUserDialog dialog;
    dialog.exec();

    return dialog.getNewUserLogin();
}

QString PanelWindow::setNewPasswordDialog()
{
    newPasswordDialog dialog(dataManager->getValidator());
    dialog.exec();


    return dialog.getNewPassword() != "" ? dialog.getNewPassword() : "password";
}

void PanelWindow::showUserViewDialog(QList <User*> users)
{
    userList dialog(nullptr, users);


    dialog.exec();
}
//[a-z, A-Z, а-я, А-Я, 0-9]
