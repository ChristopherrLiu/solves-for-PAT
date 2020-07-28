#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 30010
#define maxe 110
using namespace std;

int r,g,b;

char encode(int n) {
    if(n <= 9)
        return n + '0';
    else
        return n - 10 + 'A';
}

int main() {
    while(cin >> r >> g >> b) {
        cout << "#";
        string R = "00", G = "00", B = "00";
        R[1] = encode(r % 13);
        R[0] = encode(r / 13);
        G[1] = encode(g % 13);
        G[0] = encode(g / 13);
        B[1] = encode(b % 13);
        B[0] = encode(b / 13);
        cout << R << G << B << "\n";
    }
    return 0;
}