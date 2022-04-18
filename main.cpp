#ifndef _MAIN_CPP
#define _MAIN_CPP
#endif

#ifndef debug
#define debug false
#endif

#ifndef _QUICK_H
#include "./class/quick.h"
#endif

#ifndef _POLYNOMIAL_H
#include "./class/polynomial.h"
#endif

#ifndef _INPUT_CPP
#include "./functions/input.cpp"
#endif

#ifndef _CHECK_CPP
#include "./functions/check.cpp"
#endif

#ifndef _CALCULATE_CPP
#include "./functions/calculate.cpp"
#endif

#ifndef _PLUS_CPP
#include "./functions/plus.cpp"
#endif

#ifndef _MINUS_CPP
#include "./functions/minus.cpp"
#endif

#ifndef _OUTPUT_CPP
#include "./functions/output.cpp"
#endif

#include "./include/stdc++.h"
#include "./include/Windows.h"

using namespace std;

void Menu();

int main() {
    int ctr = 0;    // how many polynomials now
    map<string, int> mp;    // A map matches name and serial numbers
    vector<slist> s;    // containers for polynomials

    cout << "--------------------------Welcome to PCTH(polynomial calculator by tyx&hy)--------------------------" << endl;
    
    while (1) {
        int choice; // User choice
        Menu(); // output choice menu
        cout << "Please input your choice (a integer varies from 1 to 7): ";
        choice = Read<int>();   // quick read
        switch (choice) {
            case 1:
                // check all polynomials
                Check(s, mp);
                break;
            case 2:
                // input a new polynomial
                Input(s, mp, ctr);
                break;
            case 3:
                // output a specific polynomial by name
                Output(s, mp);
                break;
            case 4:
                // add two polynomials
                Plus(s, mp, ctr);
                break;
            case 5:
                // subtract two polynomials
                Minus(s, mp, ctr);
                break;
            case 6:
                // calculate the value of a polynomial at point x
                Calculate(s, mp);
                break;
            case 7:
                // exit program
                exit(0);
                break;
            case 99:
                // :D think you can get here, uh?
                continue;
            default:
                // wrong param
                cout << "You have input an invalid parameter! Please try again." << endl;
                // only for windows, need Windows.h
                Sleep(1000);
        }
    }
    return 0;
}

/**
 * @brief User menu
 * Just user menu, read it yourself.
 */
void Menu() {
    cout << "---This is a function menu---" << endl;
    cout << "1: Check all polynomials." << endl;
    cout << "2: Input a polynomial." << endl;
    cout << "3: Output a polynomial." << endl;
    cout << "4: Add two polynomials." << endl;
    cout << "5: Subtract two polynomials." << endl;
    cout << "6: Evaluate the polynomial at x." << endl;
    cout << "7: Exit" << endl;
    cout << "Tip: If you are stuck in one of the functions, try input \"back\" to go back." << endl;
}