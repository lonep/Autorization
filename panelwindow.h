#ifndef PANELWINDOW_H
#define PANELWINDOW_H

#include <QWidget>
#include <QMap>
class LoginDataManager;
class User;
namespace Ui {
class panelWindow;
}

class PanelWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PanelWindow(QWidget *parent = nullptr, LoginDataManager* datamanager = nullptr);
    ~PanelWindow();

    QString showChangePasswordDialog(QString oldPassword);
    QString showNewUserDialog();
    QString setNewPasswordDialog();

    void showUserViewDialog(QList <User*> users);

private:
    Ui::panelWindow *ui;
    LoginDataManager* dataManager;
};

#endif // PANELWINDOW_H
