#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"
#include "validator.h"
#include <QMessageBox>

ChangePasswordDialog::ChangePasswordDialog( Validator *validator, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePasswordDialog)
{
    ui->setupUi(this);
    this->validator = validator;

    connect(ui->acceptButton, QPushButton::clicked, this, [this, validator]()
    {

        if (ui->oldPassword->text() == oldPassword)
        {
            if (ui->newPassword->text() == ui->repeatPassword->text() && validator->validatePassword(ui->newPassword->text()))
                {
                    newPassword = ui->repeatPassword->text();
                    accept();
                }
            else
                {
                    QMessageBox error;
                    error.setText("Incorrect password. Password should contains only english, russian alphabet or numbers");
                    error.exec();
                }
        }
        else
        {

            QMessageBox error;
            error.setText("Passwords are different");
            error.exec();

        }
    });
}

ChangePasswordDialog::~ChangePasswordDialog()
{
    delete ui;
}

void ChangePasswordDialog::setOldPassword(QString password)
{
    oldPassword = password;
}

QString ChangePasswordDialog::getNewPassword()
{
    return newPassword;
}
