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
#define maxe 12
using namespace std;

char a[maxe], b[maxe];
int t, last, num, maxDeep;
int n, root, children[maxn], father[maxn], lson[maxn], rson[maxn];
bool flag;

void bfs() {
    queue<int> que;
    que.push(root);
    while(que.size()) {
        t = que.front();
        que.pop();
        if(t != -1)
            last = t;
        if(t == -1)
            break;
        que.push(lson[t]);
        que.push(rson[t]);
    }

    while(que.size()) {
        t = que.front();
        que.pop();
        if(t != -1)
            flag = true;
    }
} 

int main() {
    while(~scanf("%d", &n)) {
        memset(father, -1, sizeof(father));
        getchar();
        for(int i = 0; i < n; ++i) {
            scanf("%s%s", a, b);
            getchar();
            if(a[0] == '-')
                lson[i] = -1;
            else {
                num = atoi(a);
                lson[i] = num;
                father[num] = i;
            }
            if(b[0] == '-')
                rson[i] = -1;
            else {
                num = atoi(b);
                rson[i] = num;
                father[num] = i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(father[i] == -1)
                root = i;
        }
        bfs();
        if(flag) {
            printf("NO %d\n", root);
        }
        else {
            printf("YES %d\n", last);
        }
    }
    return 0;
}