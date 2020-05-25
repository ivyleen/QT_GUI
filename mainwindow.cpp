#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
// for opening a new window with model approach (everything on the stack)
//#include "seconddialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)) );
    // if we want to disconnect it
    //disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)) );
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("<html><b>First line</b><br><u>Second</u> line</html>");
}


void MainWindow::on_pushButton_2_clicked()
{
    // test with critical, information, question, warning
    QMessageBox::critical(this, tr("The title"), tr("Message"));
}


void MainWindow::on_newWindow_clicked()
{
    // after the button is clicked open the new window
    // modal approach
    //SecondDialog secDialogObj;
    //secDialogObj.setModal(true);
    //secDialogObj.exec();

    //modeless approach
    secDialogObj = new SecondDialog(this);
    secDialogObj->show();
}

