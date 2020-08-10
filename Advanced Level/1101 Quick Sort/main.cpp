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
#define maxe 10
using namespace std;

int n;
int seq[maxn];
int lmax[maxn], rmin[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &seq[i]);
            lmax[i] = max(lmax[i - 1], seq[i]);
        }
        rmin[n + 1] = 1e9 + 1;
        for(int i = n; i >= 1; --i) {
            rmin[i] = min(rmin[i + 1], seq[i]);
        }
        int ans = 0;
        vector<int> ansIds;
        for(int i = 1; i <= n; ++i) {
            if(seq[i] > lmax[i - 1] && seq[i] < rmin[i + 1]) {
                ++ans;
                ansIds.push_back(seq[i]);
            }
        }
        printf("%d\n", ans);
        for(int i = 0; i < ans; ++i)
            printf("%d%c", ansIds[i], i == ans - 1 ? '\n' : ' ');
        if(ans == 0)
            printf("\n");
    }
    return 0;
}