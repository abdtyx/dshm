#ifndef _CALCULATE_CPP
#define _CALCULATE_CPP
#endif

#ifndef _POLYNOMIAL_H
#include "../class/polynomial.h"
#endif

#ifndef debug
#define debug false
#endif

#include "../include/stdc++.h"

using namespace std;

/**
 * @brief calculate the value of a polynomial at point x
 * 
 * @param s container
 * @param mp <string, int> name, position in vector<slist>
 */
void Calculate(vector<slist> s, map<string, int> mp) {

    // debugger
    if (debug) {
        cout << "This is calculate." << endl;
        return;
    }


    cout << "Please input the name of polynomial you want to calculate f(x): ";
    string name;
    cin >> name;

    // Prevent stuck
    if (name == "back") {return;}

    // robustness, in case of input a non-exist name
    while (mp.find(name) == mp.end()) {
        cout << "The polynomial doesn't exist! Please try again: ";
        cin >> name;
        if (name == "back") {return;}
    }

    // calculate f(x)
    cout << "Please input value of x: ";
    double x;
    cin >> x;
    slist poly = s[mp[name]];

    // output value of f(x)
    cout << "The polynomial f(x) = ";
    poly.output();
    cout << "f(" << x << ") = " << poly.calculate(x) << endl;
    return;
}