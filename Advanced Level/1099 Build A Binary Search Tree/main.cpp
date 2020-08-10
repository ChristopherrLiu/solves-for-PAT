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
#define maxn 110
#define maxe 10
using namespace std;

int n, tot;
int seq[maxn];
int lson[maxn], rson[maxn], key[maxn];

void inOrder(int cur) {
    if(cur == -1)
        return;
    inOrder(lson[cur]);
    key[cur] = seq[tot++];
    inOrder(rson[cur]);
}

void bfs() {
    queue<int> que;
    que.push(0);
    while(que.size()) {
        int t = que.front();
        que.pop();
        if(t == 0)
            printf("%d", key[t]);
        else
            printf(" %d", key[t]);
        if(lson[t] != -1)
            que.push(lson[t]);
        if(rson[t] != -1)
            que.push(rson[t]);
    }
    printf("\n");
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &lson[i], &rson[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &seq[i]);
        }
        sort(seq, seq + n);
        inOrder(0);
        bfs();
    }
    return 0;
}