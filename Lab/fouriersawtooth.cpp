#include <cmath>
#include <iostream>
#include <fstream>
using namespace std; 

double pi = 3.1415926536; 

double sawtooth(double x, int nmax ) {
   double sum = 0.0;
   int n = 1;
   while (n < nmax)
   {
    sum = sum + pow(-1, n+1) / n * sin(n * x);
    n = n + 1;
   };
   sum =sum * 2 / pi;
   return sum;
}

int main() {
    int nmax;
    cout << "An upper-limit integer to the Fourier sum:";
    cin >> nmax;
    int steps = 100;
    double xmin = 0.0;
    double xmax = 4 * pi;
    string lab = to_string(nmax);
    string csvFileName = "sawtooth_" + lab + ".csv";
    ofstream outfile;
    outfile.open(csvFileName);
    double dx = (xmax - xmin) / steps;
    double x = xmin;
    while (x < xmax) {
        outfile << x << "," << sawtooth(x, nmax) << "\n";
        x = x + dx;
    };
    cout << "Output written to" << csvFileName << "\n";
    outfile.close();
    return 0;
}