#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addparametersdialog.h"
#include "calculator/calculator.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->resultTable->setColumnCount(3);

    for(int i = 0; i < 3; i++)
        ui->resultTable->setColumnWidth(i,ui->resultTable->width()/3);


    ui->resultTable->setHorizontalHeaderLabels({"Parâmetros","Metodo de Newton-Raphson","Metodo de Newton-Raphson adaptado" });
}

void MainWindow::insertOnTable(QList<QString> insertList)
{
    ui->resultTable->setRowCount(ui->resultTable->rowCount() + 1);

    int row = ui->resultTable->rowCount()-1;

    for(int column = 0; column < 3; column++)
    {
        QTableWidgetItem *item = ui->resultTable->item(row, column);
        if(!item)
            item = new QTableWidgetItem();
        item->setText(insertList.at(column));
        ui->resultTable->setItem(row, column, item);
    }

}

void MainWindow::on_addParametersButton_clicked()
{
    AddParametersDialog *dialog = new AddParametersDialog(this);
    connect(dialog, &AddParametersDialog::onAccepted, this, &MainWindow::on_parameterDialog_Accepted);
    dialog->exec();
}

void MainWindow::on_parameterDialog_Accepted(double a3, double a2, double x0, double lambda, double precision)
{
    Calculator *calculator = new Calculator();

    double newtonMethodResult = calculator->newtonMethod(a3, a2, x0, precision);

    double adaptedNewtonMethodResult = calculator->newtonMethodWithFL(a3, a2, x0, precision, nullptr, lambda);

    //todo: INSERIR DADOS NA TABELA E EVITAR EDIÇÃO
}



