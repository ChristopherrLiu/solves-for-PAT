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
#define maxe 22
using namespace std;

struct Node {
    int key;
    Node* lson;
    Node* rson;
    Node(int k_) {
        key = k_, lson = nullptr, rson = nullptr;
    }
};

int m, n, u, v, lca, preOrder[maxn];
Node* root;
bool flagu, flagv;

Node* restore(int l, int r) {
    if(l > r) {
        return nullptr;
    }
    else if(l == r) {
        Node* cur = new Node(preOrder[l]);
        return cur;
    }
    else {
        int mid = l + 1;
        while(mid <= r && preOrder[mid] < preOrder[l]) mid++;
        Node* cur = new Node(preOrder[l]);
        cur->lson = restore(l + 1, mid - 1);
        cur->rson = restore(mid, r);
        return cur;
    }
}

void search() {
    Node* curu = root;
    Node* curv = root;
    while(curu && curv && curu == curv) {
        lca = curu->key;
        if(u == v && curu->key == u)
            break;
        if(u > curu->key)
            curu = curu->rson;
        else if(u < curu->key)
            curu = curu->lson;
        if(v > curv->key)
            curv = curv->rson;
        else if(v < curv->key)
            curv = curv->lson;
        
    }
    while(curu) {
        if(u > curu->key)
            curu = curu->rson;
        else if(u < curu->key)
            curu = curu->lson;
        else {
            flagu = true;
            break;
        }
    }
    while(curv) {
        if(v > curv->key)
            curv = curv->rson;
        else if(v < curv->key)
            curv = curv->lson;
        else {
            flagv = true;
            break;
        }
    }
}

int main() {
    while(~scanf("%d %d", &m, &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &preOrder[i]);
        root = restore(0, n - 1);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            flagu = flagv = false;
            search();
            if(!flagu && !flagv) {
                printf("ERROR: %d and %d are not found.\n", u, v);
            }
            else if(!flagu) {
                printf("ERROR: %d is not found.\n", u);
            }
            else if(!flagv) {
                printf("ERROR: %d is not found.\n", v);
            }
            else if(u == lca) {
                printf("%d is an ancestor of %d.\n", u, v);
            }
            else if(v == lca) {
                printf("%d is an ancestor of %d.\n", v, u);
            }
            else {
                printf("LCA of %d and %d is %d.\n", u, v, lca);
            }
        }
    }
    return 0;
}