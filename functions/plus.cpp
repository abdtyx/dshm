#ifndef _PLUS_CPP
#define _PLUS_CPP
#endif

#ifndef _POLYNOMIAL_H
#include "../class/polynomial.h"
#endif

#ifndef debug
#define debug false
#endif

#include "../include/stdc++.h"

using namespace std;

void Plus(vector<slist> s, map<string, int> mp) {
    if (debug) {
        cout << "This is plus." << endl;
        return;
    }
    cout << "Please input two names of polynomial to add: ";
    string name1, name2;
    cin >> name1, name2;
    while (mp.find(name1) == mp.end()) {
        cout << "The first polynomial doesn't exist! Please try again: ";
        cin >> name1;
    }
    while (mp.find(name2) == mp.end()) {
        cout << "The second polynomial doesn't exist! Please try again: ";
        cin >> name2;
    }
}