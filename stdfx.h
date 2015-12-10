//
// Created by Michal Miszczyszyn on 04/12/15.
//

#ifndef MODELLING_AND_SIMULATION_OF_SYSTEMS_STDFX_H
#define MODELLING_AND_SIMULATION_OF_SYSTEMS_STDFX_H

#include <iostream>
#include <cmath>
#include <functional>
#include "gnuplot-iostream.h"

using ode_fn = std::function<double(const double a, const double b)>;
using ode_fn_cref = const ode_fn &;

#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_STDFX_H
