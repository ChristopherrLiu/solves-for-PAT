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
#define maxe 10
using namespace std;

int n, m, q, k, u, v, cycles[maxn], mapp[maxn][maxn];
bool flag, vis[maxn];

void dfs(int id) {
    vis[cycles[id]] = true;
    if(id + 1 < k && mapp[cycles[id]][cycles[id + 1]] == 1)
        dfs(id + 1);
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            mapp[u][v] = 1;
            mapp[v][u] = 1;
        }
        scanf("%d", &q);
        for(int i = 0; i < q; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j)
                scanf("%d", &cycles[j]);
            flag = true;
            if(k != n + 1)
                flag = false;
            else if(cycles[0] != cycles[n])
                flag = false;
            else {
                memset(vis, false, sizeof(vis));
                dfs(0);
                for(int j = 1; j <= n; ++j)
                    if(!vis[j])
                        flag = false;
                if(mapp[cycles[k - 2]][cycles[k - 1]] == 0)
                    flag = false;
            }
            if(flag)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}