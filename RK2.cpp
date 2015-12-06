//
// Created by Michal Miszczyszyn on 04/12/15.
//

#include "RK2.h"

RK2::RK2(ode_fn_cref fn, const double X0, const double EPS, const double a) : eps(EPS), a(a), n(0), fn(fn), xn(X0)
{
    // @todo: calculate this
    this->h = this->eps;
}

std::pair<double, double> RK2::make_step()
{
    ++this->n;
    const double tn = a + n * h;
    const double next_x = xn + h * fn(xn + 0.5 * h * fn(tn, xn), tn + 0.5 * h);
    this->xn = next_x;

    return this->get_result();
}

std::pair<double, double> RK2::get_result()
{
    const double tn = a + n * h;
    return std::make_pair(tn, this->xn);
}
