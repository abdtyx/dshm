#ifndef _CHECK_CPP
#define _CHECK_CPP
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
 * @brief check all polynomials
 * 
 * @param s container
 * @param mp <string, int> name, position in vector<slist>
 */
void Check(vector<slist> s, map<string, int> mp) {

    // debugger
    if (debug) {
        cout << "This is check." << endl;
        return;
    }

    // if no polynomial at all
    if (s.size() == 0) {
        cout << "There is no polynomial now." << endl;
        return;
    }

    // if polynomial, output all of the polynomials
    for (auto key : mp) {
        cout << key.first << '\t';
        s[key.second].output();
    }
    return;
}