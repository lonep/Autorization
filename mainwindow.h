#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "panelwindow.h"
#include "loginmanager.h"



#include "cryptopassword.h"

#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow getUi();
    void test();

    PanelWindow *panelWindow;
    void showMistakeLabel();
    void showAboutDialog();

    bool showCryptoPasswordDialog();
private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent * event);

    LoginManager *loginManager;

signals:
    void clicked();
};
#endif // MAINWINDOW_H
