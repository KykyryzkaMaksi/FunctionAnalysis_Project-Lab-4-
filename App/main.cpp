#include <iostream>
#include "FunctionAnalysis.h"

static double parabola(double x) { return (x - 2.0) * (x - 2.0) + 1.0; }
static double hill(double x) { return -x * x + 4.0 * x; }

int main() {
    double x = 0, fx = 0, v = 0;

    if (fa_findMinimum(parabola, 0, 5, 1e-9, 200, &x, &fx) == FA_OK)
        std::cout << "min: x=" << x << " f=" << fx << "\n";

    if (fa_findMaximum(hill, 0, 5, 1e-9, 200, &x, &fx) == FA_OK)
        std::cout << "max: x=" << x << " f=" << fx << "\n";

    if (fa_evaluate(parabola, 3.0, &v) == FA_OK)
        std::cout << "f(3)=" << v << "\n";

    if (fa_derivative(parabola, 3.0, 1e-5, &v) == FA_OK)
        std::cout << "f'(3)=" << v << "\n";

    return 0;
}