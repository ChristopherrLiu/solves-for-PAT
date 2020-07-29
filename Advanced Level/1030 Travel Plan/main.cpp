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
#define maxn 510
#define maxe 250010
using namespace std;

struct Edge {
    int to, len, cost, next;
    void set(int to_, int len_, int cost_, int next_) {
        to = to_, len = len_, cost = cost_, next = next_;
    }
};

struct State {
    int to, dist, costs;
    void set(int to_, int dist_, int costs_) {
        to = to_, dist = dist_, costs = costs_;
    }
    bool operator< (const State other) const {
        return dist != other.dist ? dist > other.dist : (costs != other.costs ? costs > other.costs : false);
    }
};

int n, m, s, t, u, v, w, c;
int cnt, head[maxn];
int dist[maxn], costs[maxn], pre[maxn];
Edge edges[maxe];
bool vis[maxn];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(pre, -1, sizeof(pre));
    memset(dist, 0x3f, sizeof(dist));
    memset(costs, 0x3f, sizeof(costs));
}

void add(int from, int to, int len, int cost) {
    edges[cnt].set(to, len, cost, head[from]);
    head[from] = cnt++;
}

void dijkstra() {
    priority_queue<State> que;
    State initial, t;
    initial.set(s, 0, 0);
    dist[s] = costs[s] = 0;
    que.push(initial);
    while(!que.empty()) {
        t = que.top();
        que.pop();
        if(vis[t.to])
            continue;
        vis[t.to] = true;
        for(int i = head[t.to]; i != -1; i = edges[i].next) {
            if(!vis[edges[i].to]) {
                if(dist[edges[i].to] > t.dist + edges[i].len) {
                    pre[edges[i].to] = t.to;
                    dist[edges[i].to] = t.dist + edges[i].len;
                    costs[edges[i].to] = t.costs + edges[i].cost;
                    State newS;
                    newS.set(edges[i].to, dist[edges[i].to], costs[edges[i].to]);
                    que.push(newS);
                }
                else if(dist[edges[i].to] == t.dist + edges[i].len && costs[edges[i].to] > t.costs + edges[i].cost) {
                    pre[edges[i].to] = t.to;
                    costs[edges[i].to] = t.costs + edges[i].cost;
                    State newS;
                    newS.set(edges[i].to, dist[edges[i].to], costs[edges[i].to]);
                    que.push(newS);
                }
            }
        }
    }
}

int main() {
    while(~scanf("%d %d %d %d", &n, &m, &s, &t)) {
        init();
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d %d", &u, &v, &w, &c);
            add(u, v, w, c), add(v, u, w, c);
        }
        dijkstra();
        vector<int> path;
        path.push_back(t);
        for(int i = pre[t]; i != -1; i = pre[i])
            path.push_back(i);
        for(int i = path.size() - 1; i >= 0; --i)
            printf("%d ", path[i]);
        printf("%d %d\n", dist[t], costs[t]);
    }
    return 0;
}