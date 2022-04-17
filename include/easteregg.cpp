#ifndef _EASTEREGG_CPP
#define _EASTEREGG_CPP
#endif

#include "stdc++.h"

using namespace std;

void easteregg() {
    // cout << "Congratulations! You have found an easteregg!" << endl;
    float x, y, a;
    for (y = 1.5; y > -1.5; y -= 0.1) {
        for (x = -1.5; x < 1.5; x += 0.05) {
            a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
        }
        system("color 0c");
        putchar('\n');
    }
    return;
}