#include <iostream>
#include <fstream>
#include <string>

using namespace std ; 

int main() {
    string fileName = "data.txt";

    ofstream fout(fileName);                  
    fout << "This file is called " << fileName << '\n';
    fout << "The name contains " << fileName.size() << " characters" << '\n';
    fout.close();

    cout << "Output written to " << fileName << '\n';
    return 0;
}

