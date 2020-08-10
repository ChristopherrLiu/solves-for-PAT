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
#define maxn 15
#define maxe 21
#define maxk 2
using namespace std;

char a, b;
int n, root, father[maxn], lson[maxn], rson[maxn];
bool flag;

void bfs() {
    queue<int> que;
    que.push(root);
    while(que.size()) {
        int t = que.front();
        que.pop();
        if(t == root)
            printf("%d", t);
        else
            printf(" %d", t);
        if(rson[t] != -1)
            que.push(rson[t]);
        if(lson[t] != -1)
            que.push(lson[t]);
    }
    printf("\n");
}   

void inOrder(int cur) {
    if(cur == -1)
        return;
    inOrder(rson[cur]);
    if(!flag) {
        flag = true;
        printf("%d", cur);
    }
    else
        printf(" %d", cur);
    inOrder(lson[cur]);
}

int main() {
    while(~scanf("%d", &n)) {
        memset(father, -1, sizeof(father));
        getchar();
        for(int i = 0; i < n; ++i) {
            scanf("%c %c", &a, &b);
            getchar();
            if(a == '-')
                lson[i] = -1;
            else {
                lson[i] = a - '0';
                father[a - '0'] = i;
            }
            if(b == '-')
                rson[i] = -1;
            else {
                rson[i] = b - '0';
                father[b - '0'] = i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(father[i] == -1)
                root = i;
        }
        bfs();
        inOrder(root);
        printf("\n");
    }
    return 0;
}