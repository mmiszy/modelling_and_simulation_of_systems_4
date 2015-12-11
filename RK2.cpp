//
// Created by Michal Miszczyszyn on 04/12/15.
//

#include "RK2.h"

RK2::RK2(ode_fn_cref fn, const double X0, const double EPS, const double a, const double b) : eps(EPS), a(a), b(b),
                                                                                              n(0), fn(fn), xn(X0)
{
    this->h = std::abs(b - a);
    double tau;
    do {
        this->n = 0;
        auto res1 = this->make_step().second;

        this->n = 0;
        this->h = this->h / 2.0;
        this->make_step();
        auto res2 = this->make_step().second;
        tau = std::abs(res2 - res1);
    } while (tau > eps);
    this->n = 0;
    this->h = 0.9 * this->h * this->h;
    std::cout << "h: " << this->h << std::endl;
}

const std::pair<double, double> RK2::make_step()__attribute__ ((optnone))
{
    const double tn = this->get_tn();
    ++this->n;
    const double next_x = xn + h * fn(xn + 0.5 * h * fn(xn, tn), tn + 0.5 * h);
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
