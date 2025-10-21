#include <iostream>
using namespace std;

int main() {
    int n = 1;
    while (n <= 20) {
        int t = n * (n + 1) / 2; 
        cout << t << ' ';
        n = n + 1 ;
    }
    return 0;
}