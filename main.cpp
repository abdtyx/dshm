#ifndef _MAIN_CPP
#define _MAIN_CPP
#endif

#ifndef debug
#define debug false
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

using namespace std;

void menu();

int main() {
    cout << "--------------------------Welcome to PCTH(polynomial calculator by tyx&hy)--------------------------" << endl;
    while (1) {
        int choice;
        menu();
        cout << "Please input your choice (a integer varies from 1 to 7): ";
        cin >> choice;
    }
    return 0;
}

void menu() {
    cout << "---This is a function menu---" << endl;
}