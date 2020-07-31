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
#define maxn 210
#define maxe 10010
using namespace std;

int n, m, l, c;
int seq[maxe], dp[maxe], id[maxn], cnt;

int main() {
    while(~scanf("%d", &n)) {
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", &c);
            id[c] = ++cnt;
        }
        cnt = 0;
        scanf("%d", &l);
        for(int i = 0; i < l; ++i) {
            scanf("%d", &c);
            if(id[c]) {
                seq[cnt++] = id[c];
            }
        }
        if(cnt == 0) {
            puts("0");
            continue;
        }
        int ans = 1;
        dp[0] = 1;
        for(int i = 1; i < cnt; ++i) {
            dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(seq[j] <= seq[i]) {
                    if(dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}