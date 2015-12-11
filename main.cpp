#include "stdfx.h"
#include "RK2.h"

int main()
{
    const double start = 0.0;
    const double stop = 1.0;

    double EPS;
    double X0;

    std::cout << "Podaj epsilon:\n";
    std::cin >> EPS;
    std::cout << "\nPodaj x0:\n";
    std::cin >> X0;
    std::cout << "\n\n" << std::endl;

    RK2 rk2([](double xt, double t) {
        return std::sin(10.0 * t);
        return xt / (1.0 + t);
    }, X0, EPS, start, stop);

    Gnuplot gp;

    gp << "set xlabel 't'\n";
    gp << "set ylabel 'x(t)'\n";
    gp << "set xrange [t=0:1]\n";
    gp << "set grid\n";
    gp << "set pointsize 0.5\n";
    gp << "plot '-' with lines title 'x(t)'\n";
    gp << "0 " << X0 << "\n";

    while (rk2.should_run())
    {
        auto result = rk2.make_step();
        gp << result.first << " " << result.second << "\n";
//        std::cout << "t: " << result.first << " xn: " << result.second << std::endl;
    }

    gp << "e\n";

    auto result = rk2.get_result();
    std::cout  << "t: " << result.first << " xn: " << result.second << std::endl;

    return 0;
}
