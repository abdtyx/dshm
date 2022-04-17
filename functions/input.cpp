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

void Input(vector<slist>& s, map<string, int>& mp, int& ctr) {
    if (debug) {
        cout << "This is input." << endl;
        return;
    }
    vector<pid> v;
    cout << "Please input vale of n: ";
    int n;
    // cin >> n;
    n = Read<int>();
    if (n == 2147483647) {return;}
    cout << "Input format: a1*x^b1 + a2*x^b2 + ... + an*x^bn" << endl;
    cout << "Example: a1 b1 a2 b2 ... an bn" << endl;
    for (int i = 0; i < n; i++) {
        double an;
        int bn;
        cin >> an;
        bn = Read<int>();
        if (bn == 2147483647) {return;}
        v.push_back(make_pair(bn, an));
    }
    cout << "Please name this polynomial (No space or keyword suck as \"back\"!): ";
    string name;
    cin >> name;
    if (name == "back") {return;}
    while (mp.find(name) != mp.end()) {
        // invalid name
        cout << "Name exists! Please rename this polynomial: ";
        cin >> name;
        // Prevent stuck
        if (name == "back") {return;}
    }
    // valid name
    mp[name] = ctr++;
    slist sl = construct(v);
    cout << "Polynomial " << name << " is constructed. " << endl;
    sl.output();
    s.push_back(sl);
    // return sl;
    return;
}