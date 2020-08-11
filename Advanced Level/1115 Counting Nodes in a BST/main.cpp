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

int n, key, maxDeep, n1, n2;

struct Node {
    int key;
    Node* lson;
    Node* rson;
    Node(int d) :
        key(d),
        lson(nullptr),
        rson(nullptr)
    {}
};

Node* root;

void insert() {
    int deep = 0;
    if(root == nullptr) {
        root = new Node(key);
        ++deep;
        maxDeep = max(maxDeep ,deep);
        return;
    }
    Node* cur = root;
    Node* pre = nullptr;
    
    while(cur) {
        if(key > cur->key)
            pre = cur, cur = cur->rson;
        else
            pre = cur, cur = cur->lson;
        ++deep;
    }
    cur = new Node(key);
    if(pre)
        if(pre->key < key)
            pre->rson = cur;
        else
            pre->lson = cur;
    ++deep;
    maxDeep = max(maxDeep, deep);
}

void dfs(Node* cur, int deep) {
    if(!cur)
        return;
    
    dfs(cur->lson, deep + 1);
    dfs(cur->rson, deep + 1);

    if(deep == maxDeep)
        n1++;
    else if(deep == maxDeep - 1)
        n2++;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &key);
            insert();
        }
        dfs(root, 1);
        printf("%d + %d = %d\n", n1, n2, n1 + n2);
    }
    return 0;
}