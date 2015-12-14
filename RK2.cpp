//
// Created by Michal Miszczyszyn on 04/12/15.
//

#include "RK2.h"

RK2::RK2(ode_fn_cref fn, const double X0, const double EPS, const double a, const double b) : eps(EPS), a(a), b(b),
                                                                                              n(0), fn(fn), xn(X0)
{
    this->h = EPS;
    double tau;
    do {
        this->xn = X0;
        this->n = 0;
        auto res1 = this->make_step().second;

        this->xn = X0;
        this->n = 0;
        this->h = this->h / 2.0;
        this->make_step();
        auto res2 = this->make_step().second;
        tau = 1.0 / 3.0 * std::abs(res2 - res1);
    } while (tau > eps);
    this->n = 0;
    this->xn = X0;
    this->h = 0.9 * this->h * this->h;
    std::cout << "h: " << this->h << std::endl;
}

const std::pair<double, double> RK2::make_step()__attribute__ ((optnone))
{
    ++this->n;
    const double tn = this->get_tn();
    const double next_x = xn + h * fn(xn + 0.5 * h * fn(xn, tn), tn + 0.5 * h);
//    const double k1 = h * fn(xn, tn);
//    const double k2 = h * fn(xn + 0.5 * k1 * h, tn + 0.5 * h);
//    const double k3 = h * fn(xn + 0.5 * k2 * h, tn + 0.5 * h);
//    const double k4 = h * fn(xn + k3 * h, tn + h);
//    const double dxn = 1.0/6.0 * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
//    const double next_x = xn + dxn;
    this->xn = next_x;

    auto result = this->get_result();
    return result;
}

const std::pair<double, double> RK2::get_result() const
{
    return std::make_pair(this->get_tn(), this->xn);
}

const bool RK2::should_run() const
{
    return (this->b - this->get_tn()) >= 0.0;
}

const double RK2::get_tn() const
{
    return a + n * h;
}
