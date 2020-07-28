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
#define maxn 1010
#define maxe 1000010
using namespace std;

struct Edge {
    int to, next;
    void set(int to_, int next_) {
        this->to = to_, this->next = next_;
    }
};

int n, m, k, u, v;
int cnt, head[maxn];
int blockNum, dfnTag, dfn[maxn], low[maxn], parent[maxn];
int addEdgeNum[maxn];
Edge edges[maxe];
bool vis[maxn], isCutPoint[maxn], isolatedCity[maxn];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int from, int to) {
    edges[cnt].set(to, head[from]);
    head[from] = cnt++;
}

void tarjan(int node) {
    vis[node] = true;
    low[node] = dfn[node] = dfnTag++;
    if(dfn[node] == 0) {
        int sonNum = 0;
        for(int i = head[node]; i != -1; i = edges[i].next) {
            if(!vis[edges[i].to]) {
                sonNum++;
                parent[edges[i].to] = node;
                tarjan(edges[i].to);
            }
        }
        if(sonNum > 1) {
            isCutPoint[node] = true;
            addEdgeNum[node] = sonNum - 1;
        }
        if(sonNum == 0) {
            isolatedCity[node] = true;
        }
    }
    else {
        for(int i = head[node]; i != -1; i = edges[i].next) {
            if(!vis[edges[i].to]) {
                parent[edges[i].to] = node;
                tarjan(edges[i].to);
                low[node] = min(low[edges[i].to], low[node]);
                if(low[edges[i].to] >= dfn[node]) {
                    isCutPoint[node] = true;
                    addEdgeNum[node]++;
                }
            }
            else if(parent[node] != edges[i].to)
                low[node] = min(low[node], dfn[edges[i].to]);
        }
    }
}

int main() {
    while(~scanf("%d %d %d", &n, &m, &k)) {
        init();
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            add(u, v), add(v, u);
        }
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                dfnTag = 0;
                tarjan(i);
                ++blockNum;
            }
        }
        for(int i = 0; i < k; ++i) {
            scanf("%d", &u);
            if(isCutPoint[u])
                printf("%d\n", blockNum - 1 + addEdgeNum[u]);
            else if(isolatedCity[u])
                printf("%d\n", blockNum - 2);
            else
                printf("%d\n", blockNum - 1);
        }
    }
    return 0;
}