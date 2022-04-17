#ifndef _OUTPUT_CPP
#define _OUTPUT_CPP
#endif

#ifndef debug
#define debug false
#endif

#include "../include/stdc++.h"

using namespace std;

void Output() {
    if (debug) {
        cout << "This is output." << endl;
        return;
    }
}