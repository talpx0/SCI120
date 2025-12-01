#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

using namespace std;

vector<double> get_yt(vector<double> y, vector<double> dydx, double hh)
{
    int N = y.size();
    int i = 0;
    while (i < N)
    {
        y[i] += hh * dydx[i];
        i++;
    }
    return y;
}

vector<double> rk4(function<vector<double>(vector<double>, double)> derivs,
                   vector<double> y, double x, double h)
{
    double h6 = h / 6.0;
    double hh = h / 2.0;
    double xh = x + hh;

    vector<double> yt = y;

    vector<double> D1 = derivs(yt, x);
    yt = get_yt(y, D1, hh);

    vector<double> D2 = derivs(yt, xh);
    yt = get_yt(y, D2, hh);

    vector<double> D3 = derivs(yt, xh);
    yt = get_yt(y, D3, h);

    vector<double> D4 = derivs(yt, x + h);

    int N = y.size();
    int i = 0;
    while (i < N)
    {
        y[i] += h6 * (D1[i] + 2.0 * (D2[i] + D3[i]) + D4[i]);
        i++;
    }

    return y;
}


const double sigma = 10.0;
const double beta  = 8.0 / 3.0;
const double rho   = 28.0;

vector<double> lorenzD(vector<double> y, double x)
{
    double dy0 = sigma * (y[1] - y[0]);
    double dy1 = y[0] * (rho - y[2]) - y[1];
    double dy2 = y[0] * y[1] - beta * y[2];

    return {dy0, dy1, dy2};
}


int main()
{
    ofstream fout;
    fout.open("tajectory.csv");

    int outStep = 10;
    double time = 100.0;
    double dt = 1.0e-3;
    int totalSteps = time / dt;

    cout << "steps = " << totalSteps << endl;

    double t = 0.0;
    vector<double> y = {1.0, 1.0, 1.0};

    fout << t << "," << y[0] << "," << y[1] << "," << y[2] << endl;

    int step = 1;
    while (step <= totalSteps)
    {
        y = rk4(lorenzD, y, t, dt);
        t += dt;

        if (step % outStep == 0)
        {
            fout << t << "," << y[0] << "," << y[1] << "," << y[2] << endl;
        }

        step++;
    }

    return 0;
}
