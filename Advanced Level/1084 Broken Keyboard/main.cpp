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
#define maxe 85
#define maxk 300
using namespace std;

int cnt;
char origin[maxe], show[maxe], ans[maxe];
bool vis[maxk];

char change(char c) {
    if(c >= 'a' && c <= 'z')
        c -= 32;
    return c;
}

int main() {
    while(~scanf("%s", origin)) {
        getchar();
        scanf("%s", show);
        int len1 = strlen(origin), len2 = strlen(show);
        int pt1 = 0, pt2 = 0;
        for(int i = 0; i < len1; ++i)
            origin[i] = change(origin[i]);
        for(int j = 0; j < len2; ++j)
            show[j] = change(show[j]);
        while(pt1 < len1 && pt2 < len2) {
            if(origin[pt1] != show[pt2]) {
                if(!vis[origin[pt1]])
                    ans[cnt++] = origin[pt1], vis[origin[pt1]] = true;
                ++pt1;
            }
            else {
                ++pt1;
                ++pt2;
            }
        }
        while(pt1 < len1) {
            if(!vis[origin[pt1]])
                ans[cnt++] = origin[pt1], vis[origin[pt1]] = true;
            ++pt1;
        }
        ans[cnt] = 0;
        printf("%s\n", ans);
    }
    return 0;
}