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
#define maxn 210
#define maxe 2100
using namespace std;

int n, m, q, k, u, v, len, sets[maxe];
int edges[maxn][maxn];
bool sts, ts, vis[maxn];

void dfs(int id) {
    if(id != k - 1 && vis[sets[id]])
        sts = false;
    vis[sets[id]] = true;
    if(id < k - 1) {
        if(edges[sets[id]][sets[id + 1]]) {
            len += edges[sets[id]][sets[id + 1]];
            dfs(id + 1);
        }
        else {
            ts = sts = false;
            len = -1;
        }
    }
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &len);
            edges[u][v] = len;
            edges[v][u] = len;
        }
        scanf("%d", &q);
        int ans = 1e9, ansid;
        for(int i = 0; i < q; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j)
                scanf("%d", &sets[j]);
            sts = ts = true;
            len = 0;
            memset(vis, false, sizeof(vis));
            dfs(0);
            if(k <= n) {
                ts = sts = false;
            }
            if(sets[0] != sets[k - 1])
                ts = sts = false;
            for(int i = 1; i <= n; ++i)
                if(!vis[i]) {
                    ts = sts = false;
                    break;
                }
            if(len != -1)
                printf("Path %d: %d ", i + 1, len);
            else
                printf("Path %d: NA ", i + 1);
            if(!ts)
                printf("(Not a TS cycle)\n");
            else if(!sts)
                printf("(TS cycle)\n");
            else
                printf("(TS simple cycle)\n");
            if(ts) {
                if(len < ans)
                    ans = len, ansid = i + 1;
            }
        }
        printf("Shortest Dist(%d) = %d\n", ansid, ans);
    }
    return 0;
}