#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 510
#define maxe 250001
using namespace std;
#define Abs(a) ((a) < 0 ? -(a) : a)

struct Edge {
    int to, len, next;
    void set(int to_, int len_, int next_) {
        to = to_, len = len_, next = next_;
    }
};

int cmax, n, sp, m, bikes[maxn], dis[maxn];
int ansNeed, ansBack, u, v, w, cnt, head[maxn];
Edge edges[maxe];
vector<int> pre[maxn], tempPath, ansPath;
bool vis[maxn];

void init() {
    cnt = 0;
    ansNeed = ansBack = 1e9;
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
}

void add(int from, int to, int len) {
    edges[cnt].set(to, len, head[from]);
    head[from] = cnt++;
}

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > que;
    que.push(make_pair(0, 0));
    dis[0] = 0;
    while(!que.empty()) {
        pair<int,int> t = que.top();
        que.pop();
        if(vis[t.second])
            continue;
        vis[t.second] = true;
        for(int i = head[t.second]; i != -1; i = edges[i].next) {
            if(!vis[edges[i].to]) {
                if(dis[edges[i].to] > t.first + edges[i].len) {
                    dis[edges[i].to] = t.first + edges[i].len;
                    pre[edges[i].to].clear();
                    pre[edges[i].to].push_back(t.second);
                    que.push(make_pair(dis[edges[i].to], edges[i].to));
                }
                else if(dis[edges[i].to] == t.first + edges[i].len) {
                    pre[edges[i].to].push_back(t.second);
                }
            }
        }
    }
}

void dfs(int p) {
    tempPath.push_back(p);
    if(p == 0) {
        int need = 0, back = 0;
        for(int i = tempPath.size() - 2; i >= 0; --i) {
            int pId = tempPath[i];
            if(bikes[pId] > 0) {
                back += bikes[pId];
            } else {
                if(back > -bikes[pId]) {
                    back += bikes[pId];
                }
                else {
                    need += (-bikes[pId]) - back;
                    back = 0;
                }
            }
        }
        if(need < ansNeed) {
            ansNeed = need;
            ansBack = back;
            ansPath = tempPath;
        }
        else if(need == ansNeed && back < ansBack) {
            ansBack = back;
            ansPath = tempPath;
        }
    }
    else {
        for(int i = 0; i < pre[p].size(); ++i) {
            dfs(pre[p][i]);
        }
    }
    tempPath.pop_back();
}

int main() {
    init();
    while(~scanf("%d %d %d %d", &cmax, &n, &sp, &m)) {
        cmax /= 2;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &bikes[i]);
            bikes[i] -= cmax;
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w), add(v, u, w);
        }
        dijkstra();
        dfs(sp);
        printf("%d %d", ansNeed, 0);
        for(int i = ansPath.size() - 2; i >= 0; --i)
            printf("->%d", ansPath[i]);
        printf(" %d\n", ansBack);
    }
    return 0;
}