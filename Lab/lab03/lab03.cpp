#include <iostream>
#include <cmath>
using namespace std;

void printpars(int i,double a, double b, double p ,double fp) {
    if (i == 1) {
        cout << i <<"   "<<  a << "          "<< b << "          " << p << "          " << fp << "\n";
    }
}

double bisection(function<double(double)> f, double a, double b, double eps, int N){
   f(a);
   f(b);
   if (f(a)*f(b) > 0){
       cout << "Bisection Error: invalid endpoints."<< "\n" 
            << "function must have opposite signs at endpoints." 
            << endl;
       return 1.0;
   }
   int i = 1;
   while (i <= N)
   {
    double p = (a + b) / 2.0;
    double fp = f(p);
    printpars(i,a,b,p,fp);
    if ((b-a)/2 < eps || abs(fp) < eps){
        return p;
    }
    if (f(a)* fp > 0){
        a = p;
    }
    else{
        b = p;
    }
   }

   cout << "Method failed to converge after N iterations replacing N by its actual value.";
   return 1.0;
}

double fun(double x){
    return 5*x*x - 1.75*x - 10;
    // 5.0*pow(x, 2) - 1.75*x - 10.0;
}

int main() {
    cout << "Enter endpoints a and b surrounding solution:" << "\n";
    double a, b;
    cin >> a >> b;
    if (a > b) {
        cout <<"Error: invalid endpoints." << "\n";
        return 1;
    }
    double eps = 1e-5;
    int N = 100;
    double p = bisection(fun, a, b, eps, N);
    cout << "A zero was found at p = " << p << "\n" 
         << "replacing # by the actual p value" << "\n";
    return 0;
}