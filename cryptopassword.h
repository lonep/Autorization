#ifndef CRYPTOPASSWORD_H
#define CRYPTOPASSWORD_H

#include <QDialog>
#include <QCryptographicHash>

namespace Ui {
class CryptoPassword;
}

class CryptoPassword : public QDialog
{
    Q_OBJECT

public:
    explicit CryptoPassword(QWidget *parent = nullptr);

    void setPassword(QString password);

    bool comparePasswords(QString password);

    void setInputState(bool state);
    bool getInputState();

    ~CryptoPassword();

private:
    QString password;
    bool state = false;

    Ui::CryptoPassword *ui;
};

#endif // CRYPTOPASSWORD_H
