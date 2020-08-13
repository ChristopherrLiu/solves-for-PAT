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
#define maxn 100010
#define maxe 22
using namespace std;

struct Edge {
    int from, to;
}edges[maxn];

int n, m, k, p, vsets[maxn];
bool vis[maxn];

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &edges[i].from, &edges[i].to);
        }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d", &p);
            memset(vis, false, sizeof(vis));
            bool flag = true;
            for(int j = 0; j < p; ++j) {
                scanf("%d", &vsets[j]);
                vis[vsets[j]] = true;
                if(vsets[j] >= n)
                    flag = false;
            }
            if(flag)
                for(int j = 0; j < m; ++j) {
                    if(!vis[edges[j].from] && !vis[edges[j].to]) {
                        flag = false;
                        break;
                    }
                }
            if(flag)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}