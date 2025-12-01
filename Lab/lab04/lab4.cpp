#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double differentiation(double f(double), double x, double h)
{
    return (-f(x - h) + f(x + h)) / (2 * h);
}

void derivate(double f(double), double a, double b, int n, string fname)
{
    ofstream fout;
    fout.open(fname);

    double dx = (b - a) / n;

    double x = a + dx;
    while (x < b)
    {
        fout << x << "," << differentiation(f, x, dx) << endl;
        x += dx;
    }
}

double integration(double f(double), double a, double b)
{
    double h = (b - a) / 2;
    return (h / 3) * (f(a) + 4 * f(a + h) + f(b));
}

double integrate(double f(double), double a, double b, int n, string fname)
{
    ofstream fout;
    fout.open(fname);

    double dx = (b - a) / n;
    double Itot = 0;

    double x = a;
    while (x < b)
    {
        Itot += integration(f, x, x + dx);
        fout << x << "," << Itot << endl;
        x += dx;
    }

    return Itot;
}

const double SQRT2PI = sqrt(2.0 * 3.141592653);

double gauss(double x)
{
    return exp(-x * x / 2) / SQRT2PI;
}

int main()
{
    double a = -6;
    double b = 6;
    int n = 500;

    derivate(gauss, a, b, n, "derivative.csv");
    double intabn = integrate(gauss, a, b, n, "integrate.csv");

    cout << "Integral from " << a << " to " << b << " is " << intabn << endl;

    return 0;
}
