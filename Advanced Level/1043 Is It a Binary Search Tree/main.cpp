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
#define maxn 1010
#define maxe 250010
using namespace std;

struct Node {
    int data, lson, rson;
};

bool flag, isMirror, isNotMirror;
int n, cnt, seq[maxn];
Node nodes[maxn];

int dfs(int l, int r) {
    if(flag)
        return -1;
    if(l > r)
        return -1;
    if(l == r) {
        nodes[cnt].data = seq[l];
        nodes[cnt].lson = nodes[cnt].rson = -1;
        return cnt++;
    }
    else {
        if(seq[l + 1] >= seq[l]) {
            int nr = l + 1;
            while(nr <= r && seq[nr] >= seq[l])
                ++nr;
            for(int i = nr; i <= r; ++i) {
                if(seq[i] >= seq[l]) {
                    flag = true;
                    return -1;
                }
            }
            int id = cnt++;
            if(nr <= r)
                isMirror = true;
            if(nr <= r && isNotMirror) {
                flag = true;
                return -1;
            }
            nodes[id].data = seq[l];
            nodes[id].lson = dfs(l + 1, nr - 1);
            nodes[id].rson = dfs(nr, r);
            return id;
        }
        else {
            int nr = l + 1;
            while(nr <= r && seq[nr] < seq[l])
                ++nr;
            for(int i = nr; i <= r; ++i) {
                if(seq[i] < seq[l]) {
                    flag = true;
                    return -1;
                }
            }
            int id = cnt++;
            if(nr <= r)
                isNotMirror = true;
            if(nr <= r && isMirror) {
                flag = true;
                return -1;
            }
            nodes[id].data = seq[l];
            nodes[id].lson = dfs(l + 1, nr - 1);
            nodes[id].rson = dfs(nr, r);
            return id;
        }
    }
}

void getPost(int id) {
    if(id == -1)
        return;
    getPost(nodes[id].lson);
    getPost(nodes[id].rson);
    if(flag) {
        flag = false;
        printf("%d", nodes[id].data);
    }
    else {
        printf(" %d", nodes[id].data);
    }
}

int main() {
    while(cin >> n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &seq[i]);
        }
        dfs(0, n -1);
        if(flag) {
            puts("NO");
        }
        else {
            flag = true;
            puts("YES");
            getPost(0);
            printf("\n");
        }
    }
    return 0;
}