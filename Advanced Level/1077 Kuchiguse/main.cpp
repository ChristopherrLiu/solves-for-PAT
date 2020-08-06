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
#define maxn 110
#define maxe 300
using namespace std;

int n, minLen, lens[maxn];
char strs[maxn][maxe], ans[maxe];

int main() {
    while(~scanf("%d", &n)) {
        getchar();
        minLen = 1e9;
        for(int i = 0; i < n; ++i) {
            char c = getchar();
            int cnt = 0;
            while(c != '\n') {
                strs[i][cnt++] = c;
                c = getchar();
            }
            strs[i][cnt] = 0;
            lens[i] = cnt;
            minLen = min(minLen, cnt);
        }
        int j = 1;
        for(; j <= minLen; ++j) {
            bool flag = true;
            for(int i = 1; i < n; ++i) {
                if(strs[i][lens[i] - j] != strs[i - 1][lens[i - 1] - j]) {
                    // cout << strs[i][lens[i] - j] << " " << strs[i - 1][lens[i] - j] << endl;
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(j == 1) {
            puts("nai");
        }
        else {
            strcpy(ans, strs[0] + lens[0] - j + 1);
            printf("%s\n", ans);
        }
    }
    return 0;
}