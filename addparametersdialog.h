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

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void onAccepted(double a3, double a2, double x0, double stop_condition, double lambda);

private:
    Ui::AddParametersDialog *ui;

    void init();
    void sendWarning();
};

#endif // ADDPARAMETERSDIALOG_H
