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
#define maxn 2010
#define maxe 22
using namespace std;

int n, tot, head, fa[maxn];
char expr[maxn];

struct Node {
    char key[maxe];
    int lson, rson;
};

Node nodes[maxn];

bool check(char c) {
    if(c >= '0' && c <= '9')
        return false;
    if(c >= 'a' && c <= 'z')
        return false;
    if(c >= 'A' && c <= 'Z')
        return false;
    return true;
}

void dfs(int curId) {
    if(curId == -1)
        return;
    if(curId != head && check(nodes[curId].key[0]))
        expr[tot++] = '(';
    dfs(nodes[curId].lson);
    int len = strlen(nodes[curId].key);
    for(int i = 0; i < len; ++i)
        expr[tot++] = nodes[curId].key[i];
    dfs(nodes[curId].rson);
    if(curId != head && check(nodes[curId].key[0]))
        expr[tot++] = ')';
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            getchar();
            scanf("%s%d %d", nodes[i].key, &nodes[i].lson, &nodes[i].rson);
            fa[nodes[i].lson] = i;
            fa[nodes[i].rson] = i;
        }
        for(int i = 1; i <= n; ++i)
            if(fa[i] == 0)
                head = i;
        dfs(head);
        expr[tot] = 0;
        printf("%s\n", expr);
    }
    return 0;
}