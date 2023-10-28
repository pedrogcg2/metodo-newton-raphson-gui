#ifndef ADDPARAMETERSDIALOG_H
#define ADDPARAMETERSDIALOG_H

#include <QDialog>

namespace Ui {
class AddParametersDialog;
}

class AddParametersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddParametersDialog(QWidget *parent = nullptr);
    ~AddParametersDialog();

    double getLambda();
    double getPrecision();
    double getA3();
    double getA2();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void onAccepted(double a3, double a2, double x0, double stop_condition, double lambda);

private:
    Ui::AddParametersDialog *ui;

    double m_lambda;
    double m_precision;
    double m_a3;
    double m_a2;

    void init();
};

#endif // ADDPARAMETERSDIALOG_H
