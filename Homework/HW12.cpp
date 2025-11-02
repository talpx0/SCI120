#include <iostream>
#include <cmath>  

using namespace std; 



int main() {
    cout << "Enter a number: ";

    double x;
    cin >> x;

    double* p = nullptr;

    if (x >= 0) {
        x = sqrt(x);
        p = &x;  
    }

    if (p != nullptr) {
        cout << "sqrt is " << *p << "\n";
    } else {
        cout << "invalid value\n";
        
    }

    return 0;
}