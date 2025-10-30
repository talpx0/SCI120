#include <iostream>
using namespace std;
int main() {
    int x = 42;
    int val,  val2;
    int* p = &x;       // p holds the ADDRESS of x
    cout << *p << "\n";  // dereference -> 42
    bool istrue ; 
    *p = 7;            // write through the pointer
    cout << x << "\n";   // now 7
}