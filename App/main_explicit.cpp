#include <iostream>
#include <windows.h>

double test_func(double x) { return x * x - 4.0; }
double test_deriv(double x) { return 2.0 * x; }

typedef int (*RF_NEWTON)(double(*)(double), double(*)(double), double, double, int, double*);

int main() {
    std::cout << "=== Stage 3: Explicit Linking (LoadLibrary) ===" << std::endl;

    HMODULE hLib = LoadLibraryA("RootFinder.dll");

    if (hLib == NULL) {
        std::cout << "Error: Could not load RootFinder.dll!" << std::endl;
        return 1;
    }
    std::cout << "[+] RootFinder.dll loaded successfully." << std::endl;

    RF_NEWTON rf_newton = (RF_NEWTON)GetProcAddress(hLib, "rf_newton");

    if (rf_newton == NULL) {
        std::cout << "Error: Could not find function inside DLL!" << std::endl;
        FreeLibrary(hLib);
        return 1;
    }

    double root = 0.0;
    int status = rf_newton(test_func, test_deriv, 3.0, 1e-6, 100, &root);

    if (status == 0) {
        std::cout << "[Student B] Explicit Result: Found root x = " << root << std::endl;
    }
    else {
        std::cout << "[Student B] Explicit Error: " << status << std::endl;
    }

    FreeLibrary(hLib);
    return 0;
}