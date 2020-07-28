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
#define maxn 32
#define maxe 250001
using namespace std;

struct Node {
    int id, lson, rson;
};

int n, cnt, postOrder[maxn], inOrder[maxn];
Node nodes[maxn];

int solve(int pl, int pr, int il, int ir) {
    // cout << pl << " " << pr << " " << il << " " << ir << endl;
    if(pr < pl)
        return -1;
    int nodeId = cnt++;
    nodes[nodeId].id = postOrder[pr];
    int i = il;
    for(; i <= ir; ++i) {
        if(inOrder[i] == postOrder[pr])
            break;
    }
    nodes[nodeId].lson = solve(pl, pl + i - il - 1, il, i - 1);
    nodes[nodeId].rson = solve( pl + i - il, pr - 1, i + 1, ir);
    return nodeId;
}

void bfs() {
    queue<int>que;
    que.push(0);
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        if(t == 0)
            printf("%d", nodes[t].id);
        else
            printf(" %d", nodes[t].id);
        if(nodes[t].lson != -1)
            que.push(nodes[t].lson);
        if(nodes[t].rson != -1)
            que.push(nodes[t].rson);
    }
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &postOrder[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &inOrder[i]);
        solve(0, n - 1, 0, n - 1);
        bfs();
    }
    return 0;
}