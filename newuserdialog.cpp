#include "newuserdialog.h"
#include "ui_newuserdialog.h"

newUserDialog::newUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUserDialog)
{
    ui->setupUi(this);

    connect(ui->accept, QPushButton::clicked, this, [this]()
    {
        newUserLogin = ui->lineEdit->text();
        accept();
    });
}

newUserDialog::~newUserDialog()
{
    delete ui;
}

QString newUserDialog::getNewUserLogin()
{
    return newUserLogin;
}
