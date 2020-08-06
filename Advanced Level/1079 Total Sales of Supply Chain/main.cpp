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
#define maxn 100010
#define maxe 300
using namespace std;

struct Edge {
    int to, next;
    void set(int to_, int next_) {
        to = to_, next = next_;
    }
};

int n, k, t, amo[maxn];
double p, r, ans;
int cnt, head[maxn];
Edge edges[maxn * 10];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(amo, -1, sizeof(amo));
}

void add(int from, int to) {
    edges[cnt].set(to, head[from]);
    head[from] = cnt++;
}

void dfs(int cur, int deep) {
    if(amo[cur] != -1) {
        ans += amo[cur] * p * pow(1.0 + r, deep);
    }
    else {
        for(int i = head[cur]; i != -1; i = edges[i].next) {
            dfs(edges[i].to, deep + 1);
        }
    }
}

int main() {
    init();
    while(~scanf("%d %lf %lf", &n, &p, &r)) {
        r /= 100;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &k);
            if(k == 0)
                scanf("%d", &amo[i]);
            else {
                for(int j = 0; j < k; ++j) {
                    scanf("%d", &t);
                    add(i, t);
                }
            }
        }
        dfs(0, 0);
        printf("%.1f\n", ans);
    }
    return 0;
}