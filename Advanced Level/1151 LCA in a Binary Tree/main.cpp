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
#define maxe 2100
#define DEBUG
using namespace std;

struct Node {
    int key;
    int lson, rson, parent;
    void set(int k_, int p_) {
        key = k_, parent = p_, lson = -1, rson = -1;
    }
};

int n, m, u, v, tot, lca, inOrder[maxn], preOrder[maxn];
map<int, int> key2id;
Node nodes[maxn];
bool vis[maxn];

int restore(int pl, int pr, int il, int ir, int p) {
    if(pl > pr) {
        return -1;
    }
    else if(pl == pr) {
        int cur = ++tot;
        key2id[preOrder[pl]] = cur;
        nodes[cur].set(preOrder[pl], p);
        return cur;
    }
    else {
        int mid = il;
        for(; mid <= ir; ++mid) {
            if(inOrder[mid] == preOrder[pl])
                break;
        }
        int cur = ++tot;
        key2id[preOrder[pl]] = cur;
        nodes[cur].set(preOrder[pl], p);
        nodes[cur].lson = restore(pl + 1, pl + mid - il, il, mid - 1, cur);
        nodes[cur].rson = restore(pl + mid - il + 1, pr, mid + 1, ir, cur);
        return cur;
    }
}

void dfs(int id) {
    while(id != -1) {
        if(vis[id]) {
            lca = nodes[id].key;
            break;
        }
        else{
            vis[id] = true;
        }
        id = nodes[id].parent;
    }
}

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &inOrder[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &preOrder[i]);
    }
    restore(0, n - 1, 0, n - 1, -1);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        int id1 = key2id[u];
        int id2 = key2id[v];
        if(id1 == 0 && id2 == 0) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else if(id1 == 0) {
            printf("ERROR: %d is not found.\n", u);
        }
        else if(id2 == 0) {
            printf("ERROR: %d is not found.\n", v);
        }
        else {
            memset(vis, false, sizeof(vis));
            dfs(id1); dfs(id2);
            if(lca != u && lca != v) {
                printf("LCA of %d and %d is %d.\n", u, v, lca);
            }
            else if(lca == v) {
                printf("%d is an ancestor of %d.\n", v, u);
            }
            else {
                printf("%d is an ancestor of %d.\n", u, v);
            }
        }
    }
    #ifdef DEBUG
        getchar();
        getchar();
    #endif
    return 0;
}