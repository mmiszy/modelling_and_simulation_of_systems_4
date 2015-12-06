#include "stdfx.h"
#include "RK2.h"

int main()
{
    const double EPS = 0.0000001;
    const double start = 0.0;
    const double stop = 1.0;
    const double X0 = 1.0;

    RK2 rk2([](double xt, double t) {
        return -std::sin(t);
    }, X0, EPS, start);

    for (unsigned i = 0; i < (stop - start) / EPS; ++i)
    {
        auto result = rk2.make_step();
//        std::cout << "t: " << result.first << " xn: " << result.second << std::endl;
    }

    auto result = rk2.get_result();
    std::cout << "t: " << result.first << " xn: " << result.second << std::endl;

    return 0;
}
