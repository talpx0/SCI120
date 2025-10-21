#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

int main() {
    vector<int> values{3, 27, 99, 100, 545, 7978, 45678};

    int i = 0; 
    while (i < values.size()) {
        int x = values[i];
        int digits = floor(log10(x)) + 1;
        cout << digits << '\t' << x << '\n';
        i = i + 1; 
    }
    return 0;
}