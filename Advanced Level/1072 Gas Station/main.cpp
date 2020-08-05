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
#define maxn 1020
#define maxe 15
using namespace std;

struct Edge {
    int to, len, next;
    void set(int to_, int len_, int next_) {
        to = to_, len = len_, next = next_;
    }
};

struct State {
    int to, len;
    void set(int to_, int len_) {
        to = to_, len = len_;
    }
    bool operator< (const State other) const {
        return len > other.len;
    }
};

int n, m, k, ds;
int u, v, d, dist[maxn];
char su[maxe], sv[maxe], sd[maxe];
int cnt, head[maxn];
Edge edges[maxn * maxn];
bool vis[maxn];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int from, int to, int len) {
    edges[cnt].set(to, len ,head[from]);
    head[from] = cnt++;
}

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));

    dist[s] = 0;
    State a, b;
    a.set(s, 0);

    priority_queue<State> que;
    que.push(a);
    while(que.size()) {
        b = que.top();
        que.pop();

        if(vis[b.to])
            continue;
        vis[b.to] = true;

        for(int i = head[b.to]; i != -1; i  = edges[i].next) {
            if(vis[edges[i].to])
                continue;
            if(dist[edges[i].to] > b.len + edges[i].len) {
                dist[edges[i].to] = b.len + edges[i].len;
                State newS;
                newS.set(edges[i].to, dist[edges[i].to]);
                que.push(newS);
            }
        }
    }
}

int main() {
    init();
    while(~scanf("%d %d %d %d", &n, &m, &k, &ds)) {
        for(int i = 0; i < k; ++i) {
            scanf("%s%s%s", su, sv, sd);
            if(su[0] != 'G') {
                sscanf(su, "%d", &u);
                u += m;
            }
            else {
                sscanf(su + 1, "%d", &u);
            }
            if(sv[0] != 'G') {
                sscanf(sv, "%d", &v);
                v += m;
            }
            else {
                sscanf(sv + 1, "%d", &v);
            }
            sscanf(sd, "%d", &d);
            if(u == v)
                continue;
            add(u, v, d);
            add(v, u, d);
        }
        int ansId = -1, maxDist = -1;
        double avgDIst = 1e9;
        for(int i = 1; i <= m; ++i) {
            dijkstra(i);
            bool flag = false;
            double avgTemp = 0;
            int minTemp = 1e9;
            for(int j = m + 1; j <= n + m; ++j) {
                if(dist[j] > ds) {
                    flag = true;
                    break;
                }
                if(dist[j] < minTemp)
                    minTemp = dist[j];
                avgTemp += dist[j];
            }
            if(flag)
                continue;
            avgTemp /= n;
            if(minTemp > maxDist) {
                maxDist = minTemp;
                avgDIst = avgTemp;
                ansId = i;
            }
            else if(minTemp == maxDist && avgTemp < avgDIst) {
                maxDist = minTemp;
                avgDIst = avgTemp;
                ansId = i;
            }
        }
        if(ansId == -1)
            puts("No Solution");
        else {
            printf("G%d\n", ansId);
            printf("%.1f %.1f\n", maxDist * 1.0, avgDIst);
        }
    }
    return 0;
}