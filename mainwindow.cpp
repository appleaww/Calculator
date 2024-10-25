#include "mainwindow.h"
#include "ui_mainwindow.h"
double firstNum;

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

void MainWindow::on_pB_point_released()
{
    if (ui->Result->text().contains('.') == false) {
        ui->Result->setText(ui->Result->text() + '.');
    }
}


void MainWindow::math_operations()
{
    QPushButton *qpb = (QPushButton*)sender();
    QString digits;

    if(qpb->text() == "+/-"){
        double numbers = (ui->Result->text()).toDouble();
        numbers = (-1)* numbers;
        digits = QString::number(numbers, 'g', 15);
        ui->Result->setText(digits);
    }

    if(qpb->text() == "%"){
        double numbers = (ui->Result->text()).toDouble();
        numbers = numbers * 0.01;
        digits = QString:: number (numbers, 'g', 15);
        ui->Result->setText(digits);
    }


}
void MainWindow::math_operations2()
{
    QPushButton *qpb = (QPushButton*)sender();
    firstNum ui->Result->text().toDouble();
    ui->Result->setText("");
    qpb->setChecked(true);
}

void MainWindow::on_pB_AC_released()
{
    ui->pB_min->setChecked(false);
    ui->pB_pla->setChecked(false);
    ui->pB_Divi->setChecked(false);
    ui->pB_Mult->setChecked(false);
    ui->Result->setText("0");
}


void MainWindow::on_pB_res_released()
{
    QString digits;
    double secondNum, result_num;
    secondNum ui->Result->text().toDouble();

    if(ui->pB_pla->isChecked()) {
    result_num = firstNum + secondNum;
    digits QString::number(result_num, 'g', 15);
    ui->Result->setText(digits);
    ui->pB_pla->setChecked(false);
    
    }
    if(ui->pB_min->isChecked()) {
        result_num = firstNum - secondNum;
        digits = QString:: number (result_num, 'g', 15);
        ui->Result->setText(digits);
        ui->pB_min->setChecked(false);
    
    }
    if(ui->pB_Divi->isChecked()) {
        if (secondNum == 0) {
            ui->Result->setText("He oпpeдeлeнo");
        }
        else{
            result_num = firstNum / secondNum;
            digits = QString::number (result_num, 'g', 15);
            ui->Result->setText(digits);
            ui->pB_Divi->setChecked(false);
        }

    }
    if(ui->pB_Mult->isChecked()) {
        result_num = firstNum * secondNum;
        digits = QString:: number (result_num, 'g', 15);
        ui->Result->setText(digits);
        ui->pB_Mult->setChecked(false);
    }
}
