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
#define maxn 500010
#define maxe 250010
using namespace std;

string str;
int dp[maxn], ans;

int main() {
    while(getline(cin, str)) {
        int Len = str.length();
        for(int i = 0; i < Len; ++i) {
            dp[i] = 1;
            int j = 1;
            while(i - j >= 0 && i + j < Len && str[i - j] == str[i + j])
                ++j, dp[i] += 2;
            if(i + 1 < Len && str[i] == str[i + 1]) {
                int tag = 2;
                j = 1;
                while(i - j >= 0 && i + 1 + j < Len && str[i - j] == str[i  + 1 + j])
                    ++j, tag += 2;
                dp[i] = max(dp[i], tag);
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}