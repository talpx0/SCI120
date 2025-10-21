#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Gordon,Flash";
    int cpos = name.find_first_of(',');

    string last = name.substr(0, cpos);
    name.erase(0, cpos + 1);

    cout << name << ' ' << last; 
    return 0;
}
