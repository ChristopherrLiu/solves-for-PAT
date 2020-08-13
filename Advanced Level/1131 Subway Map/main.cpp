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
#define maxe 22
using namespace std;

struct Edge {
    int to, len, linen, next;
    void set(int to_, int len_, int linen_, int next_) {
        to = to_, len = len_, linen = linen_, next = next_;
    }
};

struct State {
    int to, num, len;
    bool operator< (const State other) const {
        return len != other.len ? len > other.len : (
            num != other.num ? num > other.num : false 
        );
    }
};

int n, k, id, preId, u, v, cnt, head[maxn], pre[maxn], preln[maxn];
int dist[maxn], nums[maxn];
bool vis[maxn];
Edge edges[maxn * maxe];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int from, int to, int ln, int len) {
    edges[cnt].set(to, len, ln, head[from]);
    head[from] = cnt++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    memset(nums, 0x3f, sizeof(nums));
    State a, b;
    priority_queue<State> que;
    a.len = 0, a.to = u, a.num = 0;
    dist[u] = 0;
    nums[u] = 0;
    que.push(a);
    while(!que.empty()) {
        b = que.top();
        que.pop();
        if(b.to == v)
            break;
        if(vis[b.to])
            continue;
        vis[b.to] = true;
        for(int i = head[b.to]; i != -1; i = edges[i].next) {
            if(vis[edges[i].to])
                continue;
            int tans = 0;
            if(edges[i].linen != preln[b.to])
                tans = 1;
            if(dist[edges[i].to] > b.len + edges[i].len) {
                dist[edges[i].to] = b.len + edges[i].len;
                nums[edges[i].to] = nums[b.to] + tans;
                pre[edges[i].to] = b.to;
                preln[edges[i].to] = edges[i].linen;
                State newS;
                newS.to = edges[i].to, newS.len = dist[edges[i].to], newS.num = nums[edges[i].to];
                que.push(newS);
            }
            else if(dist[edges[i].to] == b.len + edges[i].len && nums[edges[i].to] > b.num + tans) {
                nums[edges[i].to] = b.num + tans;
                pre[edges[i].to] = b.to;
                preln[edges[i].to] = edges[i].linen;
                State newS;
                newS.to = edges[i].to, newS.len = dist[edges[i].to], newS.num = nums[edges[i].to];
                que.push(newS);
            }
        }
    }
}

int main() {
    init();
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &id);
                if(j > 0)
                    add(preId, id, i + 1, 1), add(id, preId, i + 1, 1);
                preId = id;
            }
        }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &u, &v);
            dijkstra();
            vector<int> path, linens;
            int pt = v;
            while(pre[pt] != -1) {
                path.push_back(pt);
                linens.push_back(preln[pt]);
                pt = pre[pt];
            }
            path.push_back(u);
            printf("%d\n", dist[v]);
            for(int ii = linens.size() - 1, l = path.size() - 1; ii >= 0; --ii) {
                int j = ii;
                while(j >= 0 && linens[j] == linens[ii])
                    --j;
                printf("Take Line#%d from %04d to %04d.\n", linens[ii], path[l], path[j + 1]);
                l = j + 1;
                ii = j + 1;
            }
        }
    }
    return 0;
}