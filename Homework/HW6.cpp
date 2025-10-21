#include <iostream>
#include <string>

using namespace std;

struct Cards {
    int rank;
    string suit;
};

int main() {
    Cards card{9, "clubs"};               
    cout << card.rank << " of " << card.suit << '\n';
    return 0;
}