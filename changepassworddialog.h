#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>

class Validator;

namespace Ui {
class ChangePasswordDialog;
}

class ChangePasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordDialog( Validator *validator, QWidget *parent = nullptr);
    ~ChangePasswordDialog();

    void setOldPassword(QString password);
    QString getNewPassword();


private:
    Ui::ChangePasswordDialog *ui;
    Validator *validator;

    QString oldPassword;
    QString newPassword;
};

#endif // CHANGEPASSWORDDIALOG_H
