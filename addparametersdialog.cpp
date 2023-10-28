#include "addparametersdialog.h"
#include "ui_addparametersdialog.h"
#include <QDoubleValidator>
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
    validator->setBottom(DBL_MIN);

    ui->a2ParameterInput->setValidator(validator);
    ui->a2ParameterInput->setText(QString("1"));

    ui->a3ParameterInput->setValidator(validator);
    ui->a3ParameterInput->setText(QString("1"));

    ui->lambdaParameterInput->setValidator(validator);
    ui->lambdaParameterInput->setText(QString("0.05"));

    ui->precisionParameterInput->setValidator(validator);
    ui->precisionParameterInput->setText(QString("0.001"));
}

double AddParametersDialog::getA2()
{
    return m_a2;
}

double AddParametersDialog::getA3()
{
    return m_a3;
}

double AddParametersDialog::getPrecision()
{
    return m_precision;
}


double AddParametersDialog::getLambda()
{
    return m_lambda;
}

void AddParametersDialog::on_buttonBox_accepted()
{
    double a3 = ui->a3ParameterInput->text().toDouble();
    double a2 = ui->a2ParameterInput->text().toDouble();
    double precision = ui->precisionParameterInput->text().toDouble();
    double lambda = ui->lambdaParameterInput->text().toDouble();

    emit onAccepted(a3, a2, 0.5, precision, lambda);
    accept();
}


void AddParametersDialog::on_buttonBox_rejected()
{
    return;
}

