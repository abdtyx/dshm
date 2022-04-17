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

void Output(vector<slist> s, map<string, int> mp) {
    if (debug) {
        cout << "This is output." << endl;
        return;
    }
    cout << "Please input name of polynomial: ";
    string name;
    cin >> name;
    if (name == "back") {return;}
    while (mp.find(name) == mp.end()) {
        cout << "Polynomial doesn't exist! Please try again: ";
        cin >> name;
        if (name == "back") {return;}
    }
    s[mp[name]].output();
    return;
}