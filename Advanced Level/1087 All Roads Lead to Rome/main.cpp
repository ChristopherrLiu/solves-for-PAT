#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 310
#define maxe 85
#define maxk 10
using namespace std;

int n, k, stId, seId, u, v, l;
int happ[maxn], pre[maxn];
int cnt, head[maxn];
char st[maxe], se[maxe], name[maxn][maxe];
map<string, int> name2id;
bool vis[maxn];

struct Edge {
    int to, len, next;
    void set(int to_, int len_, int next_) {
        to = to_, len = len_, next = next_;
    }
}edges[maxn * maxn];

struct Metirc {
    int lens, happs, pNum, avg_happs, num;
    void init(int id) {
        lens = 1e9;
        happs = happ[id];
        pNum = 1;
        avg_happs = happ[id];
        num = 0;
    }
}metrics[maxn];

struct State {
    int to, lens, happs, avg_happs;
    bool operator< (const State other) const {
        return lens != other.lens ? lens > other.lens : (
            happs != other.happs ? happs < other.happs : (
                avg_happs != other.avg_happs ? avg_happs < other.avg_happs : false
            )
        );
    } 
};

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < n; ++i)
        metrics[i].init(i);
}

void add(int from, int to, int len) {
    edges[cnt].set(to, len, head[from]);
    head[from] = cnt++;
}

void dijkstra() {
    metrics[stId].lens = 0;
    metrics[stId].num = 1;
    metrics[stId].pNum = 0;
    priority_queue<State> que;
    State a, b;
    a.to = stId, a.lens = 0, a.happs = happ[stId], a.avg_happs = happ[stId];
    que.push(a);
    while(que.size()) {
        b = que.top();
        que.pop();
        if(vis[b.to])
            continue;
        vis[b.to] = true;
        for(int i = head[b.to]; i != -1; i = edges[i].next) {
            if(vis[edges[i].to])
                continue;
            if(metrics[edges[i].to].lens > b.lens + edges[i].len) {
                metrics[edges[i].to].lens = b.lens + edges[i].len;
                metrics[edges[i].to].pNum = metrics[b.to].pNum + 1;
                metrics[edges[i].to].happs = b.happs + happ[edges[i].to];
                metrics[edges[i].to].avg_happs = metrics[edges[i].to].happs / metrics[edges[i].to].pNum;
                metrics[edges[i].to].num = metrics[b.to].num;
                pre[edges[i].to] = b.to;
                State newS;
                newS.to = edges[i].to, newS.lens = metrics[edges[i].to].lens, newS.happs = metrics[edges[i].to].happs, newS.avg_happs = metrics[edges[i].to].avg_happs;
                que.push(newS);
            }
            else if(metrics[edges[i].to].lens == b.lens + edges[i].len && metrics[edges[i].to].happs < b.happs + happ[edges[i].to]) {
                metrics[edges[i].to].pNum = metrics[b.to].pNum + 1;
                metrics[edges[i].to].happs = b.happs + happ[edges[i].to];
                metrics[edges[i].to].avg_happs = metrics[edges[i].to].happs / metrics[edges[i].to].pNum;
                metrics[edges[i].to].num += metrics[b.to].num;
                pre[edges[i].to] = b.to;
                State newS;
                newS.to = edges[i].to, newS.lens = metrics[edges[i].to].lens, newS.happs = metrics[edges[i].to].happs, newS.avg_happs = metrics[edges[i].to].avg_happs;
                que.push(newS);
            }
            else if(metrics[edges[i].to].lens == b.lens + edges[i].len && metrics[edges[i].to].happs == b.happs + happ[edges[i].to] && metrics[edges[i].to].avg_happs < (b.happs + happ[edges[i].to]) / (metrics[b.to].pNum + 1)) {
                metrics[edges[i].to].pNum = metrics[b.to].pNum + 1;
                metrics[edges[i].to].happs = b.happs + happ[edges[i].to];
                metrics[edges[i].to].avg_happs = metrics[edges[i].to].happs / metrics[edges[i].to].pNum;
                metrics[edges[i].to].num += metrics[b.to].num;
                pre[edges[i].to] = b.to;
                State newS;
                newS.to = edges[i].to, newS.lens = metrics[edges[i].to].lens, newS.happs = metrics[edges[i].to].happs, newS.avg_happs = metrics[edges[i].to].avg_happs;
                que.push(newS);
            }
            else if(metrics[edges[i].to].lens == b.lens + edges[i].len) {
                metrics[edges[i].to].num += metrics[b.to].num;
            }
        }
    }
}

int main() {
    while(~scanf("%d %d %s", &n, &k, st)) {
        getchar();
        strcpy(name[0], st);
        name2id[st] = 0;
        for(int i = 1; i < n; ++i) {
            scanf("%s%d", name[i], &happ[i]);
            getchar();
            name2id[name[i]] = i;
            if(strcmp(name[i], "ROM") == 0)
                seId = i;
        }
        stId = name2id[st];
        init();
        for(int i = 0; i < k; ++i) {
            scanf("%s%s%d", st, se, &l);
            add(name2id[st], name2id[se], l);
            add(name2id[se], name2id[st], l);
        }
        dijkstra();
        Metirc ans = metrics[seId];
        printf("%d %d %d %d\n", ans.num, ans.lens, ans.happs, ans.avg_happs);
        vector<int>path;
        int pt = seId;
        while(pre[pt] != -1) {
            path.push_back(pt);
            pt = pre[pt];
        }
        path.push_back(pt);
        for(int i = path.size() - 1; i >= 0; --i) {
            if(i)
                printf("%s->", name[path[i]]);
            else
                printf("%s\n", name[path[i]]);
        }
    }
    return 0;
}