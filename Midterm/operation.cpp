#include <iostream>
#include <iomanip>
#include <cmath>     // abs, cos, exp, fmod, log, log10, sin, sqrt, pow, tan, atan2, acos, asin
using namespace std; 
int main() {
    cout << fixed << setprecision(6);

    double x = -3.5;
    double a = 1.0471975512; // ≈ 60 degrees in radians (π/3)
    double b = 0.5235987756; // ≈ 30 degrees in radians (π/6)

    // abs (for floating points use abs; historically fabs)
    cout << "abs(-3.5)            = " << abs(x) << "\n";

    // trig (ANGLES IN RADIANS)
    cout << "cos(pi/3)            = " << cos(a) << "\n";
    cout << "sin(pi/6)            = " << sin(b) << "\n";
    cout << "tan(pi/6)            = " << tan(b) << "\n";

    // exp / logs
    cout << "exp(1)               = " << exp(1.0) << "\n";       // e^1
    cout << "log(e^3)             = " << log(exp(3.0)) << "\n"; // natural log
    cout << "log10(1000)          = " << log10(1000.0) << "\n";  // base-10 log

    // sqrt / pow
    cout << "sqrt(9)              = " << sqrt(9.0) << "\n";
    cout << "pow(2, 3.5)          = " << pow(2.0, 3.5) << "\n";

    // fmod: floating-point remainder of x / y with sign of x
    cout << "fmod(7.5, 2.0)       = " << fmod(7.5, 2.0) << "\n"; // 1.5

    // atan2(y, x): angle of vector (x,y) in radians
    double ang = atan2(1.0, -1.0); // quadrant-aware; here 135° ≈ 2.35619 rad
    cout << "atan2(1, -1) [rad]   = " << ang << "\n";

    
    cout << "acos(0.5) [deg]      = " << acos(0.5) * 180.0 / M_PI << "\n"; 
    cout << "asin(0.5) [deg]      = " << asin(0.5) * 180.0 / M_PI << "\n"; 
}


