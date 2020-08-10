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
#define maxn 100010
#define maxe 21
#define maxk 2
using namespace std;

int n;
long double num, ans;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%llf", &num);
            ans += (n - i + 1) * num * i;
        }
        printf("%.2Lf\n", ans);
    }
    return 0;
}