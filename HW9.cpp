#include <iostream>

using namespace std;

double cylinderVolume(double height, double radius) {
    const double PI = 3.1415926;
    return PI * radius * radius * height;  
}

int main() {
    double height = 5.5;
    double radius = 2.0;

    cout << "Cylinder height and radius: " << height << ", " << radius << '\n';
    cout << "Cylinder volume = " << cylinderVolume(height, radius) << '\n';
    return 0;
}
