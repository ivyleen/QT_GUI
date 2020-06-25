#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    testDBObj = QSqlDatabase::addDatabase("QSQLITE");
    testDBObj.setDatabaseName("test.db");

    if(!testDBObj.open())
    {
        ui->label->setText("!!! Database is not connected !!!");
    }
    else
    {
        ui->label->setText("Database is connected.");
    }
}

LogIn::~LogIn()
{
    delete ui;
}


void LogIn::on_LogInButton_clicked()
{
    QString username, password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();
    qDebug() << " username : " << username << " password : " << password;

    if(!testDBObj.open())
    {
        qDebug() << "!!! Failed to open database !!!";
        return;
    }

    QSqlQuery qry;

    if(qry.exec("select * from login_info where username='" + username + "'and password=" + password + "'"))
    {
        int count = 0;
        while (qry.next())
        {
            count++;
        }

        if(count == 1)
        {
            ui->label->setText("Username and password are correct.");
        }
        if(count > 1)
        {
            ui->label->setText("Duplicated username and password.");
        }
        if(count < 1)
        {
            ui->label->setText("Username and password are not correct.");
        }
    }
}
