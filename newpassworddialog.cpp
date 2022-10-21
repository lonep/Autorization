#include "newpassworddialog.h"
#include "ui_newpassworddialog.h"

#include <QMessageBox>
#include <QErrorMessage>
#include "validator.h"


newPasswordDialog::newPasswordDialog(Validator* validator, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newPasswordDialog)
{
    ui->setupUi(this);
    this->validator = validator;

    connect(ui->pushButton, QPushButton::clicked, this, [this]()
    {
        if(returnNewPassword(ui->newPassword->text(), ui->repeatPassword->text()))
            accept();

    });

    connect(this, SIGNAL(clicked()), this, SLOT([this]()
    {
        qDebug() << "Close";
    }));
}

newPasswordDialog::~newPasswordDialog()
{
    delete ui;
}

bool newPasswordDialog::returnNewPassword(QString newPassword, QString repeatPassword)
{

    if (newPassword == repeatPassword)
    {
        qDebug() << validator->validatePassword(repeatPassword);
        if (validator->validatePassword(repeatPassword))
        {
            this->newPassword = newPassword;
            return 1;
        }
        else
        {
            QMessageBox error;
            error.setText("Incorrect password. Password should contains only oenglish, russian alphabet or numbers");
            error.exec();
        }
    }
    else
    {
        QMessageBox error;
        error.setText("Passwords are different");
        error.exec();
        return 0;
    }
    return 0;
}

QString newPasswordDialog::getNewPassword()
{
    return newPassword;
}


