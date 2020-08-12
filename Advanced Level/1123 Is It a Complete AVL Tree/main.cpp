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

int n, key;

struct Node {
    int key, sz;
    Node* lson;
    Node* rson;
    Node* parent;
    Node(int key_) : key(key_), sz(0), lson(nullptr), rson(nullptr), parent(nullptr) {}
};

Node* Root;
bool flag;

void rorateL(Node* root) {
    Node* pare = root->parent;
    Node* subR = root->rson;
    Node* subRL = root->rson->lson;

    root->rson = subRL;
    if(subRL)
        subRL->parent = root;
    
    subR->parent = pare;
    if(pare == nullptr) {
        Root = subR;
    }
    else {
        if(pare->lson == root)
            pare->lson = subR;
        else
            pare->rson = subR;
    }

    subR->lson = root;
    root->parent = subR;
        
    root->sz = subR->sz = 0;
}

void rorateR(Node* root) {
    Node* pare = root->parent;
    Node* subL = root->lson;
    Node* subLR = root->lson->rson;

    root->lson = subLR;
    if(subLR)
        subLR->parent = root;
    
    subL->parent = pare;
    if(pare == nullptr) {
        Root = subL;
    }
    else {
        if(pare->lson == root)
            pare->lson = subL;
        else
            pare->rson = subL;
    }

    subL->rson = root;
    root->parent = subL;
        
    root->sz = subL->sz = 0;
}

void rorateLR(Node* root) {
    Node* pare = root->parent;
    Node* subL = root->lson;
    Node* subLR = root->lson->rson;
    int sz = subLR->sz;

    rorateL(subL);
    rorateR(root);

    if(sz == 1) {
        subL->sz = 0;
        subLR->sz = 0;
        root->sz = -1;
    }
    else if(sz == -1) {
        subL->sz = 1;
        subLR->sz = 0;
        root->sz = 0;
    }
    else {
        subL->sz = 0;
        subLR->sz = 0;
        root->sz = 0;
    }
}

void rorateRL(Node* root) {
    Node* pare = root->parent;
    Node* subR = root->rson;
    Node* subRL = root->rson->lson;
    int sz = subRL->sz;

    rorateR(subR);
    rorateL(root);

    if(sz == 1) {
        subR->sz = -1;
        subRL->sz = 0;
        root->sz = 0;
    }
    else if(sz == -1) {
        subR->sz = 0;
        subRL->sz = 0;
        root->sz = 1;
    }
    else {
        subR->sz = 0;
        subRL->sz = 0;
        root->sz = 0;
    }
}

void insert () {
    if(Root == nullptr) {
        Root = new Node(key);
    }
    else {
        Node* cur = Root;
        Node* pre;
        while(cur) {
            if(key >= cur->key)
                pre = cur, cur = cur->rson;
            else
                pre = cur, cur = cur->lson;
        }

        cur = new Node(key);
        if(key >= pre->key)
            pre->rson = cur, cur->parent = pre;
        else
            pre->lson = cur, cur->parent = pre;
        
        while(pre) {
            if(cur == pre->lson)
                pre->sz++;
            else
                pre->sz--;
            
            if(pre->sz == 0) {
                break;
            }
            else if(pre->sz == -1 || pre->sz == 1) {
                cur = pre;
                pre = pre->parent;
            }
            else if(pre->sz == -2 || pre->sz == 2) {
                if(pre->sz == -2) {
                    if(cur->sz == 1)
                        rorateRL(pre);
                    else
                        rorateL(pre);
                }
                else {
                    if(cur->sz == 1)
                        rorateR(pre);
                    else
                        rorateLR(pre);
                }
                break;
            }
        }
    }
}

void bfs() {
    bool first = true;
    queue<Node*>que;
    que.push(Root);
    while(que.size()) {
        Node* t = que.front();
        que.pop();
        if(!t)
            break;
        if(first)
            printf("%d", t->key);
        else
            printf(" %d", t->key);
        if(first)
            first = false;
        que.push(t->lson);
        que.push(t->rson);
    }

    while(que.size()) {
        Node* t = que.front();
        que.pop();
        if(t)
            flag = false;
        if(!t)
            continue;

        if(first)
            printf("%d", t->key);
        else
            printf(" %d", t->key);
        que.push(t->lson);
        que.push(t->rson);
    }

    printf("\n");
    if(flag)
        puts("YES");
    else
        puts("NO");
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &key);
            insert();
        }
        flag = true;
        bfs();
    }
    return 0;
}