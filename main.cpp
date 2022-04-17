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
    int ctr = 0;
    map<string, int> mp;
    vector<slist> s;
    cout << "--------------------------Welcome to PCTH(polynomial calculator by tyx&hy)--------------------------" << endl;
    while (1) {
        int choice;
        Menu();
        cout << "Please input your choice (a integer varies from 1 to 7): ";
        choice = Read<int>();
        switch (choice) {
            case 1:
                Input(s, mp, ctr);
                break;
            case 2:
                Output(s, mp);
                break;
            case 3:
                Plus(s, mp);
                break;
            case 4:
                Minus();
                break;
            case 5:
                Calculate();
                break;
            case 6:
                Check();
                break;
            case 7:
                exit(0);
                break;
            case 99:
                continue;
            default:
                cout << "You have input an invalid parameter! Please try again." << endl;
                Sleep(1000);
        }
    }
    return 0;
}

void Menu() {
    cout << "---This is a function menu---" << endl;
    cout << "1: Input a polynomial." << endl;
    cout << "2: Output a polynomial." << endl;
    cout << "3: Add two polynomials." << endl;
    cout << "4: Subtract two polynomials." << endl;
    cout << "5: Evaluate the polynomial at x." << endl;
    cout << "6: Check all polynomials." << endl;
    cout << "7: Exit" << endl;
    cout << "Tip: If you are stuck in one of the functions, try input \"back\" to go back." << endl;
}