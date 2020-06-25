#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();

private slots:
    void on_LogInButton_clicked();

private:
    Ui::LogIn *ui;
    QSqlDatabase testDBObj;
};

#endif // LOGIN_H
