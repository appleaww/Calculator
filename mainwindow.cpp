#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::num()
{   
    QPushButton *qpb = (QPushButton*)sender();
    QString digits;
    if ((ui->Result->text().contains('.')) && (qpb->text() == "0"))
    {
        digits = ui->Result->text() + qpb->text();
    }
    else
    {   
        double numbers = (ui->Result->text() + qpb->text()).toDouble();
        digits = QString::number(numbers, 'g', 15);
    }

    ui->Result->setText(digits);
}
