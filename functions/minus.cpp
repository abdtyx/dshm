#ifndef _MINUS_CPP
#define _MINUS_CPP
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
 * @brief subtract two polynomials
 * 
 * @param s container
 * @param mp <string, int> name, position in vector<slist>
 * @param ctr counter
 */
void Minus(vector<slist>& s, map<string, int>& mp, int& ctr) {

    // debugger
    if (debug) {
        cout << "This is minus." << endl;
        return;
    }

    cout << "Please input two names of polynomial to subtract: ";
    string name1, name2;
    cin >> name1 >> name2;

    // Prevent stuck
    if (name1 == "back" || name2 == "back") {return;}

    // robustness, in case of input a non-exist name
    while (mp.find(name1) == mp.end()) {
        cout << "The first polynomial doesn't exist! Please try again: ";
        cin >> name1;
        if (name1 == "back") {return;}
    }

    // robustness, in case of input a non-exist name
    while (mp.find(name2) == mp.end()) {
        cout << "The second polynomial doesn't exist! Please try again: ";
        cin >> name2;
        if (name2 == "back") {return;}
    }

    // subtract them
    slist subtracter = s[mp[name1]] - s[mp[name2]];
    cout << "Operation complete. The result is: ";

    // output result
    subtracter.output();

    // name the new polynomial
    cout << "Please name this new polynomial (No space or keyword suck as \"back\"!): ";
    string name;
    cin >> name;
    if (name == "back") {return;}   // read back

    // robustness, in case of input a non-exist name
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

    // added to container, and output
    subtracter.output();
    s.push_back(subtracter);
    return;
}