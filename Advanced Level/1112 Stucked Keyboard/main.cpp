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
#define maxe 12
using namespace std;

int k, cnt, tot;
char strs[maxn], ans[maxn], stuckedChar[maxn];
bool appearNum[maxn], write[maxn];

int main() {
    while(~scanf("%d", &k)) {
        getchar();
        scanf("%s", strs);
        int len = strlen(strs);
        for(int i = 0; i < len; ++i) {
            int j = 1;
            while(strs[i + j] == strs[i]) {
                ++j;
            }
            if(j % k == 0) {
                appearNum[strs[i]] = true;
            }
            else {
                appearNum[strs[i]] = false;
            }
            i = i + j - 1;
        }
        for(int i = 0; i < len; ++i) {
            int j = 1;
            while(strs[i + j] == strs[i]) {
                ++j;
            }
            if(appearNum[strs[i]]) {
                for(int l = 0; l < j / k; ++l)
                    ans[cnt++] = strs[i];
                if(!write[strs[i]])
                    stuckedChar[tot++] = strs[i], write[strs[i]] = true;
            }
            else {
                for(int l = 0; l < j; ++l)
                    ans[cnt++] = strs[i];
            }
            i = i + j - 1;
        }
        stuckedChar[tot] = 0;
        ans[cnt] = 0;
        printf("%s\n", stuckedChar);
        printf("%s\n", ans);
    }
    return 0;
}