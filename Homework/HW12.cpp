#include <iostream>
#include <cmath>  

using namespace std; 

int hello(){
    cout << "Hello, World!\n";
    return 0;
}
int hello2(){
    cout << "Hello, World again!\n";
    return 0;
}
int good(){
    cout << "Goodbye, World!\n";
    return 0;   

}
int thanks(){
    cout << "Thanks, World!\n";
    return 0;   
}   

 

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