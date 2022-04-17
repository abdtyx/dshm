#ifndef _INPUT_CPP
#define _INPUT_CPP
#endif

#ifndef _POLYNOMIAL_H
#include "../class/polynomial.h"
#endif

#ifndef _QUICK_H
#include "../class/quick.h"
#endif

#ifndef debug
#define debug false
#endif

#include "../include/stdc++.h"

using namespace std;

/**
 * @brief input module
 * 
 * @param s container
 * @param mp <string, int> name, position in vector<slist>
 * @param ctr counter
 */
void Input(vector<slist>& s, map<string, int>& mp, int& ctr) {
    // Debugger
    if (debug) {
        cout << "This is input." << endl;
        return;
    }

    vector<pid> v; // Every item
    cout << "Please input number of items: ";
    int n;
    n = Read<int>();
    if (n == 2147483647) {return;}  // read "back"

    cout << "Input format: a1*x^b1 + a2*x^b2 + ... + an*x^bn" << endl;
    cout << "Example: a1 b1 a2 b2 ... an bn" << endl;

    for (int i = 0; i < n; i++) {
        // read polynomial of n items
        int an, bn;
        an = Read<int>();
        if (an == 2147483647) {return;} // read "back"
        bn = Read<int>();
        if (bn == 2147483647) {return;} // read "back"
        v.push_back(make_pair(bn, an)); // add it to a processor
    }

    cout << "Please name this polynomial (No space or keyword suck as \"back\"!): ";
    string name;
    cin >> name;    // the name of this polynomial
    if (name == "back") {return;}   // read back

    // robustness, in case of input an existed name
    while (mp.find(name) != mp.end()) {
        // invalid name
        cout << "Name exists! Please rename this polynomial: ";
        cin >> name;
        // Prevent stuck
        if (name == "back") {return;}
    }

    // valid name
    // add this polynomial to container
    mp[name] = ctr++;
    slist sl = construct(v);    // construct a polynomial by processor
    cout << "Polynomial " << name << " is constructed. " << endl;

    // added to container, and output 
    sl.output();
    cout << "output" << endl;
    s.push_back(sl);
    return;
}