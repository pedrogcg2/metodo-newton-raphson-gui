#include "calculator.h"
#include <math.h>

Calculator::Calculator()
{
}

double Calculator::distFunc(double a3, double a2, double d){
    return a3*std::pow(d,3) - 9*a2*d + 3;
}

double Calculator::derivedDistFunc(double a3, double a2, double d)
{
    return 3*a3*std::pow(d,2)-9*a2;
}

double Calculator::calcNextApproximation(double xk, double fxk, double dfxk)
{
    return xk - fxk/dfxk;
}

double Calculator::newtonMethod(double a3, double a2, double x, double stop_condition)
{
    double xn = calcNextApproximation(x, distFunc(a3,a2,x), centralDerivedApproximation(a3, a2, x, 0.0001));

    double d = distFunc(a3, a2, xn);

    return std::fabs(xn - x) < stop_condition || d == 0 ? xn : newtonMethod(a3, a2, xn, stop_condition);
}

double Calculator::newtonMethodWithFL(double a3, double a2, double x, double stop_condition, double *last_approximation, double lambda)
{
    double derived_x = derivedDistFunc(a3, a2, x);
    double xn , d;

    if (std::fabs(derived_x) > lambda)
    {
        xn = calcNextApproximation(x, distFunc(a3,a2,x), derived_x);
        last_approximation = &xn;
        d = distFunc(a3,a2,xn);
        return std::fabs(xn - x) < stop_condition || d == 0 ? xn : newtonMethodWithFL(a3, a2, xn, stop_condition,
                                                                                      last_approximation, lambda);
    }

    xn = calcNextApproximation(x, distFunc(a3,a2,x), derivedDistFunc(a3, a2, *last_approximation));
    d = distFunc(a3,a2,xn);
    return std::fabs(xn - x) < stop_condition || d == 0 ? xn : newtonMethodWithFL(a3, a2, xn, stop_condition,
                                                                                  last_approximation, lambda);
}


double Calculator::centralDerivedApproximation(double a3, double a2, double d, double h)
{
    return (distFunc(a3, a2, d + h) - distFunc(a3, a2, d - h))/(2*h);
}
