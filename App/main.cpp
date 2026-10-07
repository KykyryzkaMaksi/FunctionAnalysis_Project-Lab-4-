#include <iostream>
#include "RootFinder.h"         
#include "FunctionAnalysis.h"   

double test_func(double x) { return x * x - 4.0; }
double test_deriv(double x) { return 2.0 * x; }

int main() {
    std::cout << "=== Stage 3: Cross-Testing (Normal) ===" << std::endl;

    double root = 0.0;
    int status_rf = rf_newton(test_func, test_deriv, 3.0, 1e-6, 100, &root);
    if (status_rf == 0) std::cout << "[Student A] RootFinder: Found root x = " << root << std::endl;

    double min_x = 0.0, min_val = 0.0;
    int status_fa = fa_findMinimum(test_func, -5.0, 5.0, 1e-6, 100, &min_x, &min_val);
    if (status_fa == 0) std::cout << "[Student B] FunctionAnalysis: Minimum at x = " << min_x << ", f(x) = " << min_val << std::endl;

    std::cout << "\n=== Point 6: Edge Cases Testing ===" << std::endl;

    std::cout << "Test 1: Passing nullptr to RootFinder..." << std::endl;
    int err_null = rf_newton(nullptr, test_deriv, 3.0, 1e-6, 100, &root);
    std::cout << "Result: Error code " << err_null << " (Crash avoided!)" << std::endl;

    std::cout << "Test 2: Invalid precision (eps = -1.0)..." << std::endl;
    int err_eps = rf_newton(test_func, test_deriv, 3.0, -1.0, 100, &root);
    std::cout << "Result: Error code " << err_eps << " (Crash avoided!)" << std::endl;

    return 0;
}