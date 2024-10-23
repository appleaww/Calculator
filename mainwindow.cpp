#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    {
    connect(ui->pB_0,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_1,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_2,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_3,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_4,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_5,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_6,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_7,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_8,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_9,SIGNAL(released()),this,SLOT(num()));
    connect(ui->pB_pla,SIGNAL(released()),this,SLOT(math_operations2()));
    connect(ui->pB_min,SIGNAL(released()),this,SLOT(math_operations2()));
    connect(ui->pB_pam,SIGNAL(released()),this,SLOT(math_operations()));
    connect(ui->pB_Perc,SIGNAL(released()),this,SLOT(math_operations()));
    connect(ui->pB_Divi,SIGNAL(released()),this,SLOT(math_operations2()));
    connect(ui->pB_Mult,SIGNAL(released()),this,SLOT(math_operations2()));
    connect(ui->pB_AC,SIGNAL(released()),this,SLOT(math_operations()));

    ui->pB_pla->setCheckable(true);
    ui->pB_min->setCheckable(true);
    ui->pB_Divi->setCheckable(true);
    ui->pB_Mult->setCheckable(true);
}

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
