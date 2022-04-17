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

void Check() {
    if (debug) {
        cout << "This is check." << endl;
        return;
    }
}