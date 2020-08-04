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
#define maxe 110
using namespace std;

int n, m;
int seq[maxn], dp[maxn][maxe];
bool sel[maxn][maxe];

bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &seq[i]);
        }
        sort(seq + 1, seq + n + 1, cmp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if(j >= seq[i]) {
                    if(dp[i - 1][j - seq[i]] + seq[i] >= dp[i][j]) {
                        dp[i][j] = dp[i - 1][j - seq[i]] + seq[i];
                        sel[i][j] = true;
                    }
                }
            }
        }
        if(dp[n][m] != m) {
            puts("No Solution");
        }
        else {
            vector<int> ans;
            while(m) {
                while(!sel[n][m])
                    --n;
                ans.push_back(seq[n]);
                m -= seq[n];
                --n;
            }
            int i = 0;
            for(; i < ans.size() - 1; ++i) {
                printf("%d ", ans[i]);
            }
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}