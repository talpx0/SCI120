#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

double logistic(double x, double r) {
    return r * x * (1 - x);
}

int main() {
    string filename = "logistic.csv" ; 
    ofstream fout;
    fout.open(filename);
    int tranSteps = 1000;
    int simsSteps = 200;
    double rmin = 2.5;
    double rmax = 4.0;
    int r_points = 400; 
    double dr = (rmax - rmin) / (r_points -1 );
    double r = rmin;
    while (r <= rmax) {
        double x = 0.5;
        int step = 0;
        while (step < tranSteps) {
            x = logistic(x, r);
            step = step + 1;
        }
        step = 0;
        while (step < simsSteps) {
            x = logistic(x, r);
            fout << r << "," << x << "\n";
            step = step + 1;
        }

        r = r + dr;
    }
    cout << "Output written to" << filename << "\n";
    fout.close();
    return 0;
}