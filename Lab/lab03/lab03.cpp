#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>
using namespace std;

void printpars(int i, double a, double b, double p, double fp) {
    if (i == 1) {
        cout << "  i      a         b         p        fp" << '\n';
        cout << fixed << setprecision(5);
    }
    cout << setw(3) << i
         << setw(10) << a
         << setw(10) << b
         << setw(10) << p
         << setw(10) << fp << '\n';
}
double bisection(function<double(double)> f, double a, double b, double eps, int N) {
    if (f(a) * f(b) > 0) {
        cout << "Bisection Error: invalid endpoints." << '\n'
             << "function must have opposite signs at endpoints." << '\n';
        return 1;
    }
    int i = 1;
    while (i <= N) {
        double p = (a + b) / 2.0;
        double fp = f(p);
        printpars(i, a, b, p, fp);
        if ((b - a) / 2.0 < eps || fabs(fp) < eps) {
            return p;
        }
        if (f(a) * fp > 0) {
            a = p;
        } else {
            b = p;
        }
        ++i;
    }
    cout << "Method failed to converge after " << N << " iterations" << '\n';
    return 1;
}

double fun(double x) {
    return 5.0 * x * x - 1.75 * x - 10.0;
}

int main() {
    cout << "Enter endpoints a and b surrounding solution:" << '\n';
    double a, b;
    cin >> a >> b;
    if (a > b) {
        cout << "Error: invalid endpoints" << '\n';
        return 1;
    }
    double eps = 1e-5;
    int N = 100;
    double p = bisection(fun, a, b, eps, N);
    cout << "A zero was found at p = " << p << '\n';
    return 0;
}
