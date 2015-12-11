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
    const double b;

    double h;
    unsigned n;
    ode_fn_cref fn;
    double xn;

    const double get_tn() const;

public:
    RK2(ode_fn_cref fn, const double X0 = 0.0, const double EPS = 0.01, const double a = 0.0, const double b = 1.0) __attribute__ ((optnone));
    const std::pair<double, double> make_step() __attribute__ ((optnone));
    const std::pair<double, double> get_result() const __attribute__ ((optnone));
    const bool should_run() const __attribute__ ((optimize("0")));
};


#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_RK2_H
