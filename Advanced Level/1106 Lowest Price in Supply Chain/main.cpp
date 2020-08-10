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
#define maxe 110
using namespace std;

struct Edge {
    int to, next;
    void set(int to_, int next_) {
        to = to_, next = next_;
    }
};

int n, k, t, u, num;
double p, r, ans;
int cnt, head[maxn];
Edge edges[maxn * 10];

void init() {
    cnt = 0;
    ans = 1e10 + 1;
    memset(head, -1, sizeof(head));
}

void add(int from, int to) {
    edges[cnt].set(to, head[from]);
    head[from] = cnt++;
}

void dfs(int cur, int deep) {
    int coun = 0;
    for(int i = head[cur]; i != -1; i = edges[i].next) {
        ++coun;
        dfs(edges[i].to, deep + 1);
    }
    if(coun == 0) {
        double curP = p * pow(1.0 + r, deep);
        if(curP < ans) {
            ans = curP;
            num = 1;
        }
        else if(fabs(curP - ans) < 1e-6) {
            num++;
        }
    }
}

int main() {
    init();
    while(~scanf("%d %lf %lf", &n, &p, &r)) {
        r /= 100;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &u);
                add(i, u);
            }
        }
        dfs(0, 0);
        printf("%.4f %d\n", ans, num);
    }
    return 0;
}