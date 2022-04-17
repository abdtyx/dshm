#ifndef _QUICK_H
#define _QUICK_H
#endif

#ifndef _EASTEREGG_CPP
#include "../include/easteregg.cpp"
#endif

#include "../include/stdc++.h"

using namespace std;

bool bk(char ch);
bool ck(char ch);

template<typename T>
inline T Read() {
    T sum = 0, f = 1;
    char ch = getchar();
    if (bk(ch)) {
        sum = 2147483647;
        return sum * f;
    }
    if (ck(ch)) {
        easteregg();
        sum = 99;
        return sum * f;
    }
    else {
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            sum = sum * 10 + ch - '0';
            ch = getchar();
        }
        if (sum * f == 99) return 98;
        return sum * f;
    }
}
template<typename T>
inline void Print(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

/**
 * @brief Match a 
 * 
 * @param ch a character
 * @return true if matches "back"
 * @return false if not matches
 */
bool bk(char ch) {
    if (ch == 'b') {
        ch = getchar();
        if (ch == 'a') {
            ch = getchar();
            if (ch == 'c') {
                ch = getchar();
                if (ch == 'k') {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

bool ck(char ch) {
    if (ch == 't') {
        ch = getchar();
        if (ch == 'y') {
            ch = getchar();
            if (ch == 'x') {
                ch = getchar();
                if (ch == 'l') {
                    ch = getchar();
                    if (ch == 'o') {
                        ch = getchar();
                        if (ch == 'v') {
                            ch = getchar();
                            if (ch == 'e') {
                                ch = getchar();
                                if (ch == 's') {
                                    ch = getchar();
                                    if (ch == 'h') {
                                        ch = getchar();
                                        if (ch == 'y') {
                                            ch = getchar();
                                            if (ch == '&') {
                                                ch = getchar();
                                                if (ch == 'h') {
                                                    ch = getchar();
                                                    if (ch == 'y') {
                                                        ch = getchar();
                                                        if (ch == 'l') {
                                                            ch = getchar();
                                                            if (ch == 'o') {
                                                                ch = getchar();
                                                                if (ch == 'v') {
                                                                    ch = getchar();
                                                                    if (ch == 'e') {
                                                                        ch = getchar();
                                                                        if (ch == 's') {
                                                                            ch = getchar();
                                                                            if (ch == 't') {
                                                                                ch = getchar();
                                                                                if (ch == 'y') {
                                                                                    ch = getchar();
                                                                                    if (ch == 'x') {
                                                                                        return true;
                                                                                    }
                                                                                    else return false;
                                                                                }
                                                                                else return false;
                                                                            }
                                                                            else return false;
                                                                        }
                                                                        else return false;
                                                                    }
                                                                    else return false;
                                                                }
                                                                else return false;
                                                            }
                                                            else return false;
                                                        }
                                                        else return false;
                                                    }
                                                    else return false;
                                                }
                                                else return false;
                                            }
                                            else return false;
                                        }
                                        else return false;
                                    }
                                    else return false;
                                }
                                else return false;
                            }
                            else return false;
                        }
                        else return false;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}