//
// Created by Michal Miszczyszyn on 04/12/15.
//

#include "RK2.h"

RK2::RK2(ode_fn_cref fn, const double X0, const double EPS, const double a, const double b) : eps(EPS), a(a), b(b),
                                                                                              n(0), fn(fn), xn(X0)
{
    // @todo: calculate this
    this->h = this->eps;
}

const std::pair<double, double> RK2::make_step()
{
    ++this->n;
    const double tn = this->get_tn();
    const double next_x = xn + h * fn(xn + 0.5 * h * fn(tn, xn), tn + 0.5 * h);
    this->xn = next_x;

    return this->get_result();
}

const std::pair<double, double> RK2::get_result() const
{
    return std::make_pair(this->get_tn(), this->xn);
}

const bool RK2::should_run() const
{
    return this->get_tn() <= this->b;
}

const double RK2::get_tn() const
{
    return a + n * h;
}
