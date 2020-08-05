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
#define maxe 6
using namespace std;

struct Edge {
    int to, next;
    void set(int to_, int next_) {
        to = to_, next = next_;
    }
};

int n, l, m, fo, k, ans;
int cnt, head[maxn];
Edge edges[maxn * maxn];
bool vis[maxn];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int from, int to) {
    edges[cnt].set(to, head[from]);
    head[from] = cnt++;
}

void bfs(int s) {
    memset(vis, false, sizeof(vis));
    queue<pair<int, int> >que;
    que.push(make_pair(s, 0));
    vis[s] = true;
    while(!que.empty()) {
        pair<int, int> t = que.front();
        if(t.first != s) {
            ans++;
        }
        que.pop();
        for(int i = head[t.first]; i != -1; i = edges[i].next) {
            if(vis[edges[i].to])
                continue;
            if(t.second + 1 > l)
                continue;
            vis[edges[i].to] = true;
            que.push(make_pair(edges[i].to, t.second + 1));
        }
    }
}

int main() {
    init();
    while(~scanf("%d %d", &n, &l)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &m);
            for(int j = 0; j < m; ++j) {
                scanf("%d", &fo);
                if(fo == i)
                    continue;
                add(fo, i);
            }
        }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d", &fo);
            ans = 0;
            bfs(fo);
            printf("%d\n", ans);
        }
    }
    return 0;
}