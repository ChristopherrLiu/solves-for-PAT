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
#define maxe 22
using namespace std;

const int RED = 1;
const int BLACK = 0;

struct Node {
    int key, color;
    Node* lson;
    Node* rson;
    Node(int k_, int c_) : key(k_), color(c_), lson(nullptr), rson(nullptr) {}
};

int n, k, lastnum, keys[maxn];
Node* root;
bool flag;

Node* restore(int l, int r) {
    if(l > r)
        return nullptr;
    if(l == r) {
        Node* cur = new Node(abs(keys[l]), keys[l] < 0 ? RED : BLACK);
        return cur;
    }
    else {
        Node* cur = new Node(abs(keys[l]), keys[l] < 0 ? RED : BLACK);
        int temp = abs(keys[l]), mid = l + 1;
        while(mid <= r && abs(keys[mid]) <= temp)
            ++mid;
        cur->lson = restore(l + 1, mid - 1);
        cur->rson = restore(mid, r);
        return cur;
    }
}

void dfs(Node* cur, int bnum) {
    if(cur == nullptr) {
        if(lastnum == -1)
            lastnum = bnum;
        else if(bnum != lastnum)
            flag = false;
        return;
    }
    if(cur->color == RED) {
        if((cur->lson && cur->lson->color == RED) || (cur->rson && cur->rson->color == RED)) {
            flag = false;
        }
    }
    else {
        bnum++;
    }
    dfs(cur->lson, bnum);
    dfs(cur->rson, bnum);

}

void Free(Node* cur) {
    if(!cur)
        return;
    Free(cur->lson);
    Free(cur->rson);
    delete cur;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &k);
            for(int i = 0; i < k; ++i)
                scanf("%d", &keys[i]);
            root = restore(0, k - 1);
            flag = true;
            if(root->color != BLACK) {
                flag = false;
            }
            else {
                lastnum = -1;
                dfs(root, 0);
            }
            if(flag)
                puts("Yes");
            else
                puts("No");
            Free(root);
        }
    }
    return 0;
}