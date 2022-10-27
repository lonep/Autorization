#include "cryptopassword.h"
#include "ui_cryptopassword.h"

CryptoPassword::CryptoPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CryptoPassword)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked,this, [this]()
    {
        if (comparePasswords(ui->lineEdit->text()))
        {
            setInputState(true);
            accept();
        }
        else
        {
            accept();
        }
    });
}

void CryptoPassword::setPassword(QString password)
{
    this->password = password;
}

bool CryptoPassword::comparePasswords(QString password)
{
    return this->password == password;
}

void CryptoPassword::setInputState(bool state)
{
    this->state = state;
}

bool CryptoPassword::getInputState()
{
    return state;
}

CryptoPassword::~CryptoPassword()
{
    delete ui;
}
