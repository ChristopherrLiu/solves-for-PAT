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

long long n;
long long primeFactor[maxn];
int cnt, num[maxn];

void solve(long long n) {
    for(long long factor = 2; factor * factor <= n && n; ++factor) {
        if(n % factor == 0) {
            primeFactor[cnt] = factor;
            num[cnt] = 1;
            ++cnt;
            n /= factor;
        }
        while(n % factor == 0) {
            ++num[cnt - 1];
            n /= factor;
        }
    }
    if(n != 1) {
        primeFactor[cnt] = n;
        num[cnt] = 1;
        ++cnt;
    }
}

int main() {
    while(~scanf("%lld", &n)) {
        solve(n);
        printf("%lld=", n);
        if(n == 1) {
            printf("%d\n", 1);
            continue;
        }
        for(int i = 0; i < cnt; ++i) {
            if(num[i] == 1) {
                printf("%lld%c", primeFactor[i], i == cnt - 1 ? '\n' : '*');
            }
            else {
                printf("%lld^%d%c", primeFactor[i], num[i], i == cnt - 1 ? '\n' : '*');
            }
        }
    }
    return 0;
}