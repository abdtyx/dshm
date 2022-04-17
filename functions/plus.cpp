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

void Plus(vector<slist>& s, map<string, int>& mp, int& ctr) {
    if (debug) {
        cout << "This is plus." << endl;
        return;
    }
    cout << "Please input two names of polynomial to add: ";
    string name1, name2;
    cin >> name1 >> name2;
    if (name1 == "back" || name2 == "back") {return;}
    while (mp.find(name1) == mp.end()) {
        cout << "The first polynomial doesn't exist! Please try again: ";
        cin >> name1;
        if (name1 == "back") {return;}
    }
    while (mp.find(name2) == mp.end()) {
        cout << "The second polynomial doesn't exist! Please try again: ";
        cin >> name2;
        if (name2 == "back") {return;}
    }
    slist adder = s[mp[name1]] + s[mp[name2]];
    cout << "Operation complete. The result is: ";
    adder.output();
    cout << "Please name this new polynomial (No space or keyword suck as \"back\"!): ";
    string name;
    cin >> name;
    if (name == "back") {return;}
    while (mp.find(name) != mp.end()) {
        // invalid name
        cout << "Name exists! Please rename this polynomial";
        cin >> name;
        // Prevent stuck
        if (name == "back") {return;}
    }
    // valid name
    mp[name] = ctr++;
    cout << "Polynomial " << name << " is constructed. " << endl;
    adder.output();
    s.push_back(adder);
    return;
}