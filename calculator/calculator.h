
#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    Calculator();

    double newtonMethod(double a3, double a2, double x, double stop_condition);

    double newtonMethodWithFL(double a3, double a2, double x, double stop_condition, double *last_approximation, double lambda);

private:
    double centralDerivedApproximation(double a3, double a2, double d, double h);

    double derivedDistFunc(double a3, double a2, double d);

    double calcNextApproximation(double xk, double fxk, double dfxk);

    double distFunc(double a3, double a2, double d);

};

#endif // CALCULATOR_H
