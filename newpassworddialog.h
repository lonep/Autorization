#ifndef NEWPASSWORDDIALOG_H
#define NEWPASSWORDDIALOG_H

#include <QDialog>
class Validator;

namespace Ui {
class newPasswordDialog;
}

class newPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newPasswordDialog(Validator* validator, QWidget *parent = nullptr);
    ~newPasswordDialog();

    bool returnNewPassword(QString newPassword, QString repeatPassword);
    QString getNewPassword();
private:
    Ui::newPasswordDialog *ui;
    QString newPassword;

    Validator *validator;
};

#endif // NEWPASSWORDDIALOG_H
