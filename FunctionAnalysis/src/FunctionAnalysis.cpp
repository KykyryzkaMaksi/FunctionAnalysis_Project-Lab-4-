#include "FunctionAnalysis.h"
#include <cmath>

namespace {
    bool bad(double v) { return !std::isfinite(v); }

    int golden(FA_Func f, double a, double b, double eps, int maxIter, double sign, double* xExt, double* fExt) {
        if (!f || !xExt || !fExt) return FA_ERR_NULL_ARG;
        if (bad(a) || bad(b) || a >= b) return FA_ERR_INVALID_INTERVAL;
        if (!(eps > 0.0) || !std::isfinite(eps) || maxIter <= 0) return FA_ERR_BAD_PARAM;

        const double r = 0.6180339887498949;
        double c = b - r * (b - a), d = a + r * (b - a);
        double fc = sign * f(c), fd = sign * f(d);

        if (bad(fc) || bad(fd)) return FA_ERR_NOT_FINITE;

        for (int i = 0; i < maxIter; ++i) {
            if ((b - a) < eps) {
                double xm = (a + b) / 2.0;
                double fm = f(xm);
                if (bad(fm)) return FA_ERR_NOT_FINITE;
                *xExt = xm; *fExt = fm;
                return FA_OK;
            }
            if (fc < fd) {
                b = d; d = c; fd = fc;
                c = b - r * (b - a); fc = sign * f(c);
                if (bad(fc)) return FA_ERR_NOT_FINITE;
            }
            else {
                a = c; c = d; fc = fd;
                d = a + r * (b - a); fd = sign * f(d);
                if (bad(fd)) return FA_ERR_NOT_FINITE;
            }
        }
        return FA_ERR_NO_CONVERGENCE;
    }
}

extern "C" {

    int fa_evaluate(FA_Func f, double x, double* result) {
        if (!f || !result) return FA_ERR_NULL_ARG;
        if (bad(x)) return FA_ERR_BAD_PARAM;
        double v = f(x);
        if (bad(v)) return FA_ERR_NOT_FINITE;
        *result = v;
        return FA_OK;
    }

    int fa_derivative(FA_Func f, double x, double h, double* result) {
        if (!f || !result) return FA_ERR_NULL_ARG;
        if (bad(x) || bad(h) || !(h > 0.0)) return FA_ERR_BAD_PARAM;
        double f1 = f(x + h), f2 = f(x - h);
        if (bad(f1) || bad(f2)) return FA_ERR_NOT_FINITE;
        double d = (f1 - f2) / (2.0 * h);
        if (bad(d)) return FA_ERR_NOT_FINITE;
        *result = d;
        return FA_OK;
    }

    int fa_findMinimum(FA_Func f, double a, double b, double eps, int maxIter, double* xExt, double* fExt) {
        return golden(f, a, b, eps, maxIter, +1.0, xExt, fExt);
    }

    int fa_findMaximum(FA_Func f, double a, double b, double eps, int maxIter, double* xExt, double* fExt) {
        return golden(f, a, b, eps, maxIter, -1.0, xExt, fExt);
    }

}