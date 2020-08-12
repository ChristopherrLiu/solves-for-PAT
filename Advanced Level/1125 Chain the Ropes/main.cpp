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
#define maxn 10010
#define maxe 22
using namespace std;

int n;
double origin[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%lf", &origin[i]);
        sort(origin, origin + n);
        for(int i = 0; i < n - 1; ++i) {
            origin[i + 1] = (origin[i] + origin[i + 1]) / 2;
        }
        printf("%d\n", (int)origin[n - 1]);
    }
    return 0;
}