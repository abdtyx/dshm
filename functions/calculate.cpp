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

void Calculate(vector<slist> s, map<string, int> mp) {
    if (debug) {
        cout << "This is calculate." << endl;
        return;
    }
    cout << "Please input the name of polynomial you want to calculate f(x): ";
    string name;
    cin >> name;
    if (name == "back") {return;}
    while (mp.find(name) == mp.end()) {
        cout << "The polynomial doesn't exist! Please try again: ";
        cin >> name;
        if (name == "back") {return;}
    }
    cout << "Please input value of x: ";
    double x;
    cin >> x;
    slist poly = s[mp[name]];
    cout << "The polynomial f(x) = ";
    poly.output();
    cout << "f(" << x << ") = " << poly.calculate(x) << endl;
    return;
}