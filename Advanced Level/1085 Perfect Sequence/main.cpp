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
#define maxe 85
#define maxk 300
using namespace std;
typedef long long ll;

int n;
ll p, seq[maxn];

int main() {
    while(~scanf("%d %lld", &n, &p)) {
        for(int i = 0; i < n; ++i)
            scanf("%lld", &seq[i]);
        sort(seq, seq + n);
        int l = 0, r = 0, ans = 0;
        while(l < n) {
            ll curM = seq[l] * p;
            while(r < n && seq[r] <= curM)
                ++r;
            ans = max(ans, r - l);
            ++l;
        }
        printf("%d\n", ans);
    }
    return 0;
}