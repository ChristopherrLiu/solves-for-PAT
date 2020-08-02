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
#define maxn 1010
#define maxe 10
using namespace std;

struct Data {
    int g, s, k;
    Data operator+ (const Data other) const {
        Data res;
        res.k = k + other.k;
        res.s = s + other.s;
        res.g = g + other.g;
        res.s += res.k / 29;
        res.k %= 29;
        res.g += res.s / 17;
        res.s %= 17;
        return res;
    }
}a, b;

int main() {
    while(~scanf("%d.%d.%d", &a.g, &a.s, &a.k)) {
        scanf("%d.%d.%d", &b.g, &b.s, &b.k);
        Data c = a + b;
        printf("%d.%d.%d\n", c.g, c.s, c.k);
    }
    return 0;
}