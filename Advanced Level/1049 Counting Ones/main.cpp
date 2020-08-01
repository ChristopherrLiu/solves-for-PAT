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
#define maxn 12
#define maxe 10010
using namespace std;

int n, dp[maxn][maxn];

void pre() {
    for(int i = 1; i <= 9; ++i)
        dp[1][i] = 1;
    for(int i = 2; i <= 11; ++i) {
        for(int j = 1; j <= 9; ++j) {
            if(j == 1) {
                for(int k = 1; k <= i - 1; ++k)
                    dp[i][j] += dp[k][9];
                dp[i][j] += 1;
            }
            else if(j == 2){
                dp[i][j] += (int)pow(10.0, i - 1) - 1;
                dp[i][j] += dp[i][j - 1];
                for(int k = 1; k <= i - 1; ++k)
                    dp[i][j] += dp[k][9];
            }
            else {
                dp[i][j] += dp[i][j - 1];
                for(int k = 1; k <= i - 1; ++k)
                    dp[i][j] += dp[k][9];
            }
        }
    }
}

int main() {
    pre();
    while(cin >> n) {
        int temp = n, extra = 01, cnt = 1, ans = 0;
        while(temp) {
            int cur = temp % 10;
            ans += dp[cnt][cur];
            if(cur == 1)
                ans += n % extra;
            extra = extra * 10;
            temp /= 10;
            cnt++;
        }
        // if(temp == 1) {
        //     ans += n % ((int)pow(10.0, cnt - 1));
        // }
        // ans += dp[cnt][temp];
        printf("%d\n", ans);
    }
    return 0;
}