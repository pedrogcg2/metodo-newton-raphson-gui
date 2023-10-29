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
    ui->resultTable->setHorizontalHeaderLabels({"Parâmetros [a3, a2, x0, λ, ε]","Metodo de Newton-Raphson","Metodo de Newton-Raphson adaptado" });
    ui->resultTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i = 0; i < 3; i++)
        ui->resultTable->setColumnWidth(i,ui->resultTable->width()/3);

    connect(ui->resultTable, &QTableWidget::cellClicked, this, &MainWindow::on_cell_clicked);

    this->setFixedSize(this->size());
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
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
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

    QString parametersString = QString("[" + QString::number(a3) + ", " + QString::number(a2) + ", " + QString::number(x0) + ", " + QString::number(lambda) + ", " + QString::number(precision) + "]");

    QString newtonMethodResultString = QString::number(newtonMethodResult);

    QString adaptedNewtonMethodResultString = QString::number(adaptedNewtonMethodResult);

    QList<QString> insertList = {parametersString, newtonMethodResultString, adaptedNewtonMethodResultString};

    insertOnTable(insertList);
}


void MainWindow::on_removeParametersButton_clicked()
{
    QItemSelectionModel *model = ui->resultTable->selectionModel();
    QModelIndexList selected = model->selectedRows();

    QList<int> rowsToDelete;


    for(auto index : selected)
        rowsToDelete.append(index.row());

    std::sort(rowsToDelete.begin(), rowsToDelete.end(), std::greater<int>());

    for (int row : rowsToDelete)
        ui->resultTable->removeRow(row);

}


void MainWindow::on_cell_clicked(int row, int column)
{
    ui->resultTable->selectRow(row);
}
