#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginmanager.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginManager = new LoginManager();


    connect(ui->loginButton, &QPushButton::clicked,this, [this]()
    {

        if (loginManager->login(ui->login->text(), ui->password->text()))
        {
            panelWindow = new PanelWindow(nullptr, loginManager->getLoginDataManager());
            ui->mistakLabel->setEnabled(false);
            panelWindow->show();

        }
        else
        {
            ui->mistakLabel->setEnabled(true);
            ui->mistakLabel->setText(QString("Incorrect login data. %1 attempts left.").arg(3 - loginManager->gerLoginMistake()));
        }
    });

    connect(this, SIGNAL(clicked()), this, SLOT([this]()
    {
        qDebug() << "Close";
    }));

}


MainWindow::~MainWindow()
{
    delete ui;
    delete panelWindow;
}

 void MainWindow::test()
{
    qDebug() << "TEST";
}

 void MainWindow::showMistakeLabel()
 {

 }

 void MainWindow::closeEvent(QCloseEvent * event)
 {
             event->ignore();

            delete loginManager->dataManager;

             event->accept();
 }
