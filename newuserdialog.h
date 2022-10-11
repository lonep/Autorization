#ifndef NEWUSERDIALOG_H
#define NEWUSERDIALOG_H

#include <QDialog>

namespace Ui {
class newUserDialog;
}

class newUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newUserDialog(QWidget *parent = nullptr);
    ~newUserDialog();

    QString getNewUserLogin();

private:
    QString newUserLogin;

    Ui::newUserDialog *ui;
};

#endif // NEWUSERDIALOG_H
