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
#define maxe 20010
using namespace std;

struct Edge {
    int to, next;
    void set(int to_, int next_) {
        to = to_, next = next_;
    }
};

int n, u, v, connectBlock, maxDeep;
int cnt, head[maxn], f[maxn][2];
Edge edges[maxe];
bool vis[maxn];
set<int>ans;
vector<int> nodeId[maxn][2];

void init() {
    cnt = 0;
    maxDeep = -1;
    memset(head, -1, sizeof(head));
}

void add(int from, int to) {
    edges[cnt].set(to, head[from]);
    head[from] = cnt++;
}

void dfs(int p) {
    vis[p] = true;
    nodeId[p][0].push_back(p);
    nodeId[p][1].push_back(p);
    for(int i = head[p]; i != -1; i = edges[i].next) {
        int to = edges[i].to;
        if(!vis[to]) {
            dfs(to);
            if(f[p][0] < f[to][0] + 1) {
                f[p][1] = f[p][0];
                nodeId[p][1] = nodeId[p][0];
                f[p][0] = f[to][0] + 1;
                nodeId[p][0] = nodeId[to][0];
            }
            else if(f[p][0] == f[to][0] + 1) {
                for(auto pId : nodeId[to][0])
                    nodeId[p][0].push_back(pId);
                if(f[p][1] < f[to][0] + 1) {
                    f[p][1] = f[to][0] + 1;
                    nodeId[p][1] = nodeId[to][0];
                }
            }
            else if(f[p][1] < f[to][0] + 1) {
                f[p][1] = f[to][0] + 1;
                nodeId[p][1] = nodeId[to][0];
            }
            else if(f[p][1] == f[to][0] + 1) {
                for(auto pId : nodeId[to][0])
                    nodeId[p][1].push_back(pId);
            }
        }
    }
    if(f[p][0] + f[p][1] > maxDeep) {
        maxDeep = f[p][0] + f[p][1];
        ans.clear();
        for(auto pId : nodeId[p][0])
            ans.insert(pId);
        for(auto pId : nodeId[p][1])
            ans.insert(pId);
    }
    else if(f[p][0] + f[p][1] == maxDeep) {
        for(auto pId : nodeId[p][0])
            ans.insert(pId);
        for(auto pId : nodeId[p][1])
            ans.insert(pId);
    }
}

int main() {
    init();
    while(~scanf("%d", &n)) {
        for(int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            add(u, v), add(v, u);
        }
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                dfs(i);
                connectBlock++;
            }
        }
        if(connectBlock > 1) {
            printf("Error: %d components\n", connectBlock);
        }
        else {
            for(auto p : ans) {
                printf("%d\n", p);
            }
        }
    }
    return 0;
}