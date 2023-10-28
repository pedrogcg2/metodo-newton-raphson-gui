#include "addparametersdialog.h"
#include "ui_addparametersdialog.h"
#include <QDoubleValidator>
#include <QMessageBox>
#include <cfloat>

AddParametersDialog::AddParametersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddParametersDialog)
{
    ui->setupUi(this);
    init();
}

AddParametersDialog::~AddParametersDialog()
{
    delete ui;
}


void AddParametersDialog::init()
{
    QDoubleValidator *validator = new QDoubleValidator();


    ui->a2ParameterInput->setValidator(validator);
    ui->a2ParameterInput->setText(QString("1"));

    ui->a3ParameterInput->setValidator(validator);
    ui->a3ParameterInput->setText(QString("1"));

    ui->startPointParameterInput->setValidator(validator);
    ui->startPointParameterInput->setText("0.5");

    ui->lambdaParameterInput->setValidator(validator);
    ui->lambdaParameterInput->setText(QString("0.05"));

    ui->precisionParameterInput->setValidator(validator);
    ui->precisionParameterInput->setText(QString("0.001"));
}

void AddParametersDialog::on_buttonBox_accepted()
{
    if(ui->a3ParameterInput->text().isNull() || ui->a3ParameterInput->text().isEmpty()
        || ui->a2ParameterInput->text().isNull() || ui->a2ParameterInput->text().isEmpty()
        || ui->precisionParameterInput->text().isNull() || ui->precisionParameterInput->text().isEmpty()
        || ui->lambdaParameterInput->text().isNull() || ui->precisionParameterInput->text().isEmpty()
        || ui->a3ParameterInput->text().isNull() || ui->a3ParameterInput->text().isEmpty()
        )
    {
        sendWarning();
        return;
    }

    double startPoint = ui->startPointParameterInput->text().toDouble();
    double a3 = ui->a3ParameterInput->text().toDouble();
    double a2 = ui->a2ParameterInput->text().toDouble();
    double precision = ui->precisionParameterInput->text().toDouble();
    double lambda = ui->lambdaParameterInput->text().toDouble();

    if(precision == 0 || lambda == 0 || (a3 == 0 && a2 == 0))
    {
        sendWarning();
        return;
    }

    emit onAccepted(a3, a2, startPoint, precision, lambda);
    accept();
}


void AddParametersDialog::on_buttonBox_rejected()
{
    reject();
}

void AddParametersDialog::sendWarning()
{
    QMessageBox::warning(this, "Aviso", "Algo de errado com os parâmetros escolhidos");
}

