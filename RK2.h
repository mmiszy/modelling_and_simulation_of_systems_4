//
// Created by Michal Miszczyszyn on 04/12/15.
//

#ifndef MODELLING_AND_SIMULATION_OF_SYSTEMS_RK2_H
#define MODELLING_AND_SIMULATION_OF_SYSTEMS_RK2_H


#include "stdfx.h"

class RK2
{
private:
    const double eps;
    const double a;

    double h;
    unsigned n;
    ode_fn_cref fn;
    double xn;

public:
    RK2(ode_fn_cref fn, const double X0 = 0.0, const double EPS = 0.01, const double a = 0.0);
    std::pair<double, double> make_step();
    std::pair<double, double> get_result();
};


#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_RK2_H
