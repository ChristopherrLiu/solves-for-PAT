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
#define maxe 2
using namespace std;

int n, k, u, v, id, cnt, ids[maxn], birds[maxn];
int father[maxn];

void init() {
    memset(father, -1, sizeof(father));
}

int find(int root) {
    return father[root] == -1 ? root : father[root] = find(father[root]);
}

int main() {
    init();
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &birds[j]);
                if(ids[birds[j]] == 0)
                    ids[birds[j]] = ++cnt;
                if(j > 0) {
                    int fa1 = find(ids[birds[j]]);
                    int fa2 = find(ids[birds[j - 1]]);
                    if(fa1 != fa2) 
                        father[fa1] = fa2;
                }
            }
        }
        int treeNum = 0;
        for(int i = 1; i <= cnt; ++i) {
            if(father[i] == -1)
                treeNum++;
        }
        printf("%d %d\n", treeNum, cnt);
        scanf("%d", &k);
        for(int j = 0; j < k; ++j) {
            scanf("%d %d", &u, &v);
            int fa1 = find(ids[u]);
            int fa2 = find(ids[v]);
            if(fa1 != fa2) 
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}