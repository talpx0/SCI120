#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

double mc_minima(function<double(double)>f, double x, double T0, long long simSteps) {
    random_device rg;
    uniform_real_distribution<double> randDx(-1.0, 1.0);
    uniform_real_distribution<double> randOne(0.0, 1.0);
    ofstream outf;
    outf.open("convergence.csv");
    double fx = f(x);
    double xmin = x;
    double fmin = fx;
    double T = T0;
    long long step = 1;
    while (step <= simSteps) {
        double dx = randDx(rg);
        double fxdx = f(x + dx);
        double df = fxdx - fx;
        if (df <= 0.0 || randOne(rg) < exp(-df / T)) {
            x += dx;
            fx = fxdx;
            if (fx < fmin) {
                xmin = x;
                fmin = fx;
            }
        }
        outf << step << "," << x << "\n";
        T = T0 * (1.0 - (static_cast<double>(step)/static_cast<double>(simSteps)) *
        (static_cast<double>(step)/static_cast<double>(simSteps)));
        if (T < 0.0) T = 0.0;
        step = step + 1 ;
    }
    return xmin;
}

double func(double x) {
    return 480.0 + (-232.0 + (-28.0 + (10.0 + x) * x) * x) * x;
}

int main() {
    cout << "Starting x value: ";
    double xi;
    double T = 500.0;
    long long maxStep = 50000;
    double xmin = mc_minima(func, xi, T, maxStep);
    cout << "Minima at x = " << xmin << "\n";
    cout << "Minima value f(x) = " << func(xmin) << "\n";
    return 0;
}
