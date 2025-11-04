#include <iostream>
#include <iomanip>
#include <cmath>     // abs, cos, exp, fmod, log, log10, sin, sqrt, pow, tan, atan2, acos, asin

int main() {
    using std::cout;
    cout << std::fixed << std::setprecision(6);

    double x = -3.5;
    double a = 1.0471975512; // ≈ 60 degrees in radians (π/3)
    double b = 0.5235987756; // ≈ 30 degrees in radians (π/6)

    // abs (for floating points use std::abs; historically std::fabs)
    cout << "abs(-3.5)            = " << std::abs(x) << "\n";

    // trig (ANGLES IN RADIANS)
    cout << "cos(pi/3)            = " << std::cos(a) << "\n";
    cout << "sin(pi/6)            = " << std::sin(b) << "\n";
    cout << "tan(pi/6)            = " << std::tan(b) << "\n";

    // exp / logs
    cout << "exp(1)               = " << std::exp(1.0) << "\n";       // e^1
    cout << "log(e^3)             = " << std::log(std::exp(3.0)) << "\n"; // natural log
    cout << "log10(1000)          = " << std::log10(1000.0) << "\n";  // base-10 log

    // sqrt / pow
    cout << "sqrt(9)              = " << std::sqrt(9.0) << "\n";
    cout << "pow(2, 3.5)          = " << std::pow(2.0, 3.5) << "\n";

    // fmod: floating-point remainder of x / y with sign of x
    cout << "fmod(7.5, 2.0)       = " << std::fmod(7.5, 2.0) << "\n"; // 1.5

    // atan2(y, x): angle of vector (x,y) in radians
    double ang = std::atan2(1.0, -1.0); // quadrant-aware; here 135° ≈ 2.35619 rad
    cout << "atan2(1, -1) [rad]   = " << ang << "\n";
    cout << "atan2(1, -1) [deg]   = " << ang * 180.0 / M_PI << "\n";  // use <numbers> pi in C++20

    // inverse trig (results in radians)
    cout << "acos(0.5) [deg]      = " << std::acos(0.5) * 180.0 / M_PI << "\n"; // 60°
    cout << "asin(0.5) [deg]      = " << std::asin(0.5) * 180.0 / M_PI << "\n"; // 30°
}
