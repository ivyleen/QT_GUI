#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
// for opening a new window with model approach (everything on the stack)
//#include "seconddialog.h"
#include "login.h"

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

void MainWindow::on_newWindow_clicked()
{
    // after the button is clicked open the new window
    // modal approach - you will have a window open which will prevent working with the main window
    //SecondDialog secDialogObj;
    //secDialogObj.setModal(true);
    //secDialogObj.exec();

    //modeless approach - you will have n numbers of windows depends on how many times you click on
    // the button: the main window is reachable
    secDialogObj = new SecondDialog(this);
    secDialogObj->show();
}

