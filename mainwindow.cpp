#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginmanager.h"
#include "aboutprogram.h"
#include <QDir>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList <int> newList; //Костыль намеренный

    if (!showCryptoPasswordDialog())
        newList[2];


    loginManager = new LoginManager();



    connect(ui->loginButton, &QPushButton::clicked,this, [this]()
    {



        if (loginManager->login(ui->login->text(), ui->password->text()))
        {
            ui->login->clear();
            ui->password->clear();

            panelWindow = new PanelWindow(nullptr, loginManager->getLoginDataManager());
            ui->mistakLabel->setEnabled(false);

//            this->hide();
            if (!(loginManager->dataManager->getCurrentUser()->getPassword() == "password") && !panelWindow->isNewUser)
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

    connect(ui->About, QAction::triggered, this, [this](){showAboutDialog();});

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

 void MainWindow::showAboutDialog()
 {
    AboutProgram about;
    about.exec();
 }

 bool MainWindow::showCryptoPasswordDialog()
 {
    CryptoPassword dialog;
    dialog.setPassword("kopibara1");
    dialog.exec();

    return dialog.getInputState();
 }

 void MainWindow::closeEvent(QCloseEvent * event)
 {
             event->ignore();

            delete loginManager->dataManager;

             event->accept();
 }
