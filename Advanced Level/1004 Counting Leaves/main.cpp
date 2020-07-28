#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int maxe = maxn * maxn;

struct Edge {
    int to, next;
    void set(int to_, int next_) {
        to = to_, next = next_;
    }
}edges[maxe];

int n, m, currrentRoot, num, children;
int cnt, maxDeep, head[maxn], ans[maxn];

void init() {
    cnt = maxDeep = 0;
    memset(head, -1, sizeof(head));
}

void add(int from, int to) {
    edges[cnt].set(to, head[from]);
    head[from] = cnt++;
}

void dfs(int nodeId, int deep) {
    int childrenNum = 0;
    for(int i = head[nodeId]; i != -1; i = edges[i].next) {
        childrenNum++;
        dfs(edges[i].to, deep + 1);
    }
    if(!childrenNum)
        ans[deep]++;
    maxDeep = max(maxDeep, deep);
}

int main() {
    init();
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &currrentRoot, &num);
            for(int j = 0; j < num; ++j) {
                scanf("%d", &children);
                add(currrentRoot, children);
            }
        }
        dfs(1, 0);
        printf("%d", ans[0]);
        for(int i = 1; i <= maxDeep; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}