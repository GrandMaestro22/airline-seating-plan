#include "seating_functions.hpp"
#include <iostream>


using namespace std;

int main() {
    int n;
    cout << "How many seats do you want to fill:";
    cin >> n;
    fillSeats(n);
    displaySeats();

}