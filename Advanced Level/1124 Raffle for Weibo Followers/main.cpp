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
#define maxn 2010
#define maxe 22
using namespace std;

int m, n, s, cnt;
char nicknames[maxn][maxe];
char awardedNickname[maxn][maxe];
map<string, int> isAward;

int main() {
    while(~scanf("%d %d %d", &m, &n, &s)) {
        for(int i = 1; i <= m; ++i) {
            getchar();
            scanf("%s", nicknames[i]);
        }
        int pt = s;
        while(pt <= m) {
            if(isAward[nicknames[pt]] == 0) {
                isAward[nicknames[pt]] = 1;
                strcpy(awardedNickname[cnt++], nicknames[pt]);
                pt += n;
            }
            else {
                ++pt;
            }
        }
        if(!cnt)
            puts("Keep going...");
        else {
            for(int i = 0; i < cnt; ++i)
                puts(awardedNickname[i]);
        }
    }
    return 0;
}