
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addParametersButton_clicked();

    void on_parameterDialog_Accepted(double a3, double a2, double x0, double lambda, double precision);

private:
    Ui::MainWindow *ui;
    void init();
    void insertOnTable(QList<QString> insertList);
};

#endif // MAINWINDOW_H
