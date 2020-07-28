#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10010;

int k, nums[maxn], dp[maxn];
int pres[maxn];

int main() {
    while(~scanf("%d", &k)) {
        for(int i = 0; i < k; ++i)
            scanf("%d", &nums[i]);
        dp[0] = nums[0];
        pres[0] = 0;
        for(int i = 1; i < k; ++i) {
            dp[i] = nums[i];
            pres[i] = i;
            if(dp[i - 1] >= 0) {
                dp[i] += dp[i - 1];
                pres[i] = pres[i - 1];
            }
        }
        bool flag = false;
        int ans = -1, pre = 0, tail = k - 1;
        for(int i = 0; i < k; ++i) {
            if(dp[i] >= 0) {
                flag = true;
                if(dp[i] > ans) {
                    ans = dp[i];
                    pre = pres[i];
                    tail = i;
                }
            }
        }
        if(flag)
            printf("%d %d %d\n", ans, nums[pre], nums[tail]);
        else
            printf("%d %d %d\n", 0, nums[pre], nums[tail]);
    }
    return 0;
}