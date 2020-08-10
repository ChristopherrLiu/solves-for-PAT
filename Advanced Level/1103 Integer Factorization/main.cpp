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
#define maxn 410
#define maxe 21
#define maxk 2
using namespace std;

int n, k, p;
int range[maxe], factor[maxe][maxe];
int dp[maxe][maxn][maxn], sel[maxe][maxn][maxn];

void pre() {
    for(int i = 1; i <= 20; ++i)
        factor[i][1] = i;
    bool flag = false;
    range[1] = 20;
    for(int j = 2; j <= 7; ++j) {
        flag = false;
        for(int i = 1; i <= 20; ++i) {
            if(flag)
                continue;
            factor[i][j] = factor[i][j - 1] * i;
            if(factor[i][j] > 400) {
                flag = true;
                continue;
            }
            range[j] = i;
        }
    }
}

int main() {
    pre();
    while(~scanf("%d %d %d", &n, &k, &p)) {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i <= range[p]; ++i)
            dp[i][0][0] = 0;
        for(int i = 1; i <= range[p]; ++i) {
            for(int j = 1; j <= n; ++j) {
                for(int l = 1; l <= k; ++l) {
                    dp[i][j][l] = dp[i - 1][j][l];
                    for(int o = 1; o <= l && o <= j / factor[i][p]; ++o) {
                        if(dp[i - 1][j - o * factor[i][p]][l - o] == -1)
                            continue;
                        if(dp[i - 1][j - o * factor[i][p]][l - o] + o * i >= dp[i][j][l]) {
                            dp[i][j][l] = dp[i - 1][j - o * factor[i][p]][l - o] + o * i;
                            sel[i][j][l] = o;
                        }
                    }
                }
            }
        }
        if(dp[range[p]][n][k] == -1)
            printf("Impossible\n");
        else {
            int temp1 = n, temp2 = k, temp3 = range[p];
            vector<int> ansFactors;
            printf("%d = ", n);
            while(temp1) {
                while(sel[temp3][temp1][temp2] == 0)
                    --temp3;
                int num = sel[temp3][temp1][temp2];

                for(int i = 0; i < num; ++i) {
                    ansFactors.push_back(temp3);
                }
                temp1 -= num * factor[temp3][p];
                temp2 -= num;
                --temp3;
            }
            for(int i = 0; i < k; ++i)
                if(i == k - 1)
                    printf("%d^%d\n", ansFactors[i], p);
                else
                    printf("%d^%d + ", ansFactors[i], p);
        }
    }
    return 0;
}