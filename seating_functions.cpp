#include "seating_functions.hpp"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char seats[13][6];

void fillSeats(int n) {
    string ticketType;
    int seatRow;
    char seatColumn;

    // 1. Initialize seats to '*' ONLY ONCE at the start
    for(int j = 0; j < 13; j++) {
        for (int k = 0; k < 6; k++) {
            seats[j][k] = '*';
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "\nPassenger " << i + 1 << endl;
        cout << "Ticket type (First, Business, Economy): ";
        cin >> ticketType;
        cout << "Row (1-13): ";
        cin >> seatRow;
        cout << "Column (A-F): ";
        cin >> seatColumn;

        bool validSeat = false;
        while (!validSeat) {
            // Check First Class restrictions
            if ((ticketType != "first" && ticketType != "First") && (seatRow == 1 || seatRow == 2)) {
                cout << "Rows 1-2 are First Class only. Re-enter Ticket, Row, and Column: ";
                cin >> ticketType >> seatRow >> seatColumn;
            }
            // Check Business Class restrictions
            else if ((ticketType != "business" && ticketType != "Business") && (seatRow >= 3 && seatRow <= 7)) {
                cout << "Rows 3-7 are Business Class only. Re-enter Ticket, Row, and Column: ";
                cin >> ticketType >> seatRow >> seatColumn;
            }
            else {
                validSeat = true;
                cout << "Seat confirmed!\n";
            }
        }

        // Convert Column Letter to Array Index
        int colIndex;
        switch (toupper(seatColumn)) {
            case 'A': colIndex = 0; break;
            case 'B': colIndex = 1; break;
            case 'C': colIndex = 2; break;
            case 'D': colIndex = 3; break;
            case 'E': colIndex = 4; break;
            case 'F': colIndex = 5; break;
            default: colIndex = -1;
        }

        // Update the array (Row - 1 because arrays are 0-indexed)
        if(colIndex != -1 && seatRow >= 1 && seatRow <= 13) {
            seats[seatRow - 1][colIndex] = 'X';
        } else {
            cout << "Invalid row or column entered. Seat not assigned.\n";
        }
    }
}

void displaySeats() {
    cout << "\n      A B C D E F" << endl;
    for (int i = 0; i < 13; i++) {
        // Add a space for single-digit rows (1-9) to keep columns aligned
        if (i < 9) cout << "Row  " << i + 1 << " ";
        else       cout << "Row " << i + 1 << " ";

        for (int j = 0; j < 6; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
