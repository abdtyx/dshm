#ifndef _OUTPUT_CPP
#define _OUTPUT_CPP
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
 * @brief output a polynomial by name
 * 
 * @param s container
 * @param mp <string, int> name, position in vector<slist>
 */
void Output(vector<slist> s, map<string, int> mp) {
    
    // debugger
    if (debug) {
        cout << "This is output." << endl;
        return;
    }

    cout << "Please input name of polynomial: ";
    string name;
    cin >> name;    // the name of polynomial to output

    if (name == "back") {return;}   // read back

    // robustness, in case of input a non-exist name
    while (mp.find(name) == mp.end()) {
        cout << "Polynomial doesn't exist! Please try again: ";
        cin >> name;
        // Prevent stuck
        if (name == "back") {return;}
    }

    // output
    s[mp[name]].output();
    return;
}