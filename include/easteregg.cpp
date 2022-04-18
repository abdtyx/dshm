#ifndef _EASTEREGG_CPP
#define _EASTEREGG_CPP
#endif

#include "stdc++.h"

using namespace std;

/**
 * @brief Easteregg, no more description
 * No comment but a heart.
 * @param input_something_in_cmd such as tyxloveshy&hylovestyx
 * @return None
 */
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
    cout << "TangYuxiao has a warm heart." << endl << "So do HanYang." << endl;
    // What the f**k is this? I don't know. May be you should try it yourself and see what's happening.
    return;
    // TangYuxiao has a warm heart.
    // So do HanYang.
}