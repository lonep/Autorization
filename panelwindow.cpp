#include "panelwindow.h"
#include "logindatamanager.h"
#include "ui_panelwindow.h"
#include "changepassworddialog.h"
#include "newuserdialog.h"
#include "userlist.h"
#include "newpassworddialog.h"
#include "user.h"

PanelWindow::PanelWindow(QWidget *parent, LoginDataManager* dataManager) :
    QWidget(parent),
    ui(new Ui::panelWindow)
{
    ui->setupUi(this);
    ui->label->setVisible(false);

    this->dataManager = dataManager;

    connect(ui->changePassword, QPushButton::clicked, this, [this, dataManager]()
    {
       dataManager->setNewPassword(showChangePasswordDialog(dataManager->getCurrentUser()->getPassword()));
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
            if (dataManager->addNewUser(showNewUserDialog()))
            {
                ui->label->setVisible(false);
            }
            else
            {
                ui->label->setVisible(true);
            }
        }

    });

    connect(ui->userView, QPushButton::clicked, this, [this, dataManager]()
    {
        showUserViewDialog(dataManager->getUserList());

    });

    if (dataManager->getCurrentUser()->getPassword() == "password")
    {
       dataManager->getCurrentUser()->setPassword(setNewPasswordDialog());
    }
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
