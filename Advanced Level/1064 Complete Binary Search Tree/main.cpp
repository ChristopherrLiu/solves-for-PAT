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
#define maxe 11
using namespace std;

struct Node {
    int data, lson, rson;
};

int n, cnt, seq[maxn];
int bases[maxe];
Node nodes[maxn];

void pre() {
    bases[1] = 1;
    for(int i = 2; i <= 10; ++i) {
        bases[i] = bases[i - 1] + (int)pow(2.0, i - 1);
    }
}

int solve(int l, int r) {
    if(l > r)
        return -1;
    if(l == r) {
        int id = cnt++;
        nodes[id].data = seq[l];
        nodes[id].lson = nodes[id].rson = -1;
        return id;
    }
    int len = r - l + 1, i = 1, root, upper;
    for(; i <= 10; ++i) {
        if(bases[i] > len)
            break;
    }
    root = (bases[i - 1] - 1) / 2;
    upper = (bases[i] - 1) / 2;

    int remain = len - bases[i - 1];
    if(upper - root >= remain) {
        root += remain;
    }
    else {
        root += upper - root;
    }


    int id = cnt++;
    nodes[id].data = seq[l + root];
    nodes[id].lson = solve(l, l + root - 1);
    nodes[id].rson = solve(l + root + 1, r);
    return id;
}

void bfs() {
    queue<int> que;
    que.push(0);
    printf("%d", nodes[0].data);
    while(que.size()) {
        int t = que.front();
        que.pop();
        if(t)
            printf(" %d", nodes[t].data);
        if(nodes[t].lson != -1)
            que.push(nodes[t].lson);
        if(nodes[t].rson != -1)
            que.push(nodes[t].rson);
    }
    printf("\n");
}

int main() {
    pre();
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &seq[i]);
        sort(seq, seq + n);
        solve(0, n - 1);
        bfs();
    }
    return 0;
}