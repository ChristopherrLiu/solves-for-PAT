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
#define maxe 11
using namespace std;

struct Node {
    Node* lson; 
    Node* rson;
    Node* parent;
    int data, bf;
    Node(const int& d) :
        data(d) ,
        lson(nullptr) ,
        rson(nullptr) ,
        parent(nullptr) ,
        bf(0)
    {}
};

int n;
Node* root;

void rorateR(Node *p) {
    Node* psubL = p->lson;
    Node* psubR = p->lson->rson;

    p->lson = psubR;
    if(psubR)
        psubR->parent = p;

    Node* ppare = p->parent;
    psubL->rson = p;
    psubL->parent = ppare;
    p->parent = psubL;
    if(psubL->parent == nullptr) {
        root = psubL;
    }
    else {
        if(ppare->lson == p)
            ppare->lson = psubL;
        else
            ppare->rson = psubL;
    }

    p->bf = psubL->bf = 0;
}

void rorateL(Node *p) {
    Node* psubR = p->rson;
    Node* psubL = p->rson->lson;

    p->rson = psubL;
    if(psubL)
        psubL->parent = p;

    Node* ppare = p->parent;
    psubR->lson = p;
    psubR->parent = ppare;
    p->parent = psubR;
    if(psubR->parent == nullptr) {
        root = psubR;
    }
    else {
        if(ppare->lson == p)
            ppare->lson = psubR;
        else
            ppare->rson = psubR;
    }

    p->bf = psubR->bf = 0;
}

void rorateRL(Node *p) {
    Node* psubR = p->rson;
    Node* psubRL = p->rson->lson;
    int bf = psubRL->bf;
    rorateR(p->rson);
    rorateL(p);
    if(bf == -1) {
        p->bf = 0;
        psubR->bf = 1;
        psubRL->bf = 0;
    }
    else if(bf == 1) {
        p->bf = -1;
        psubR->bf = 0;
        psubRL->bf = 0;
    }
    else {
        p->bf = 0;
        psubR->bf = 0;
        psubRL->bf = 0;
    }
}

void rorateLR(Node *p) {
    Node* psubL = p->lson;
    Node* psubLR = p->lson->rson;
    int bf = psubLR->bf;
    rorateL(p->lson);
    rorateR(p);
    if(bf == -1) {
        p->bf = -1;
        psubL->bf = 0;
        psubLR->bf = 0;
    }
    else if(bf == 1) {
        p->bf = 0;
        psubL->bf = -1;
        psubLR->bf = 0;
    }
    else {
        p->bf = 0;
        psubL->bf = 0;
        psubLR->bf = 0;
    }
}

void insert(int data) {
    if(root == nullptr) {
        root = new Node(data);
        return;
    }
    Node* pare = nullptr;
    Node* cur = root;
    while(cur) {
        if(data >= cur->data) {
            pare = cur;
            cur = cur->rson;
        }
        else {
            pare = cur;
            cur = cur->lson;
        }
    }

    cur = new Node(data);

    if(cur->data >= pare->data)
        pare->rson = cur;
    else
        pare->lson = cur;
    
    cur->parent = pare;

    while(pare) {
        if(cur == pare->lson)
            pare->bf--;
        else
            pare->bf++;
        
        if(pare->bf == 0) {
            break;
        }
        else if(pare->bf == 1 || pare->bf == -1) {
            cur = pare;
            pare = pare->parent;
        }
        else if(pare->bf == 2 || pare->bf == -2) {
            if(pare->bf == 2) {
                if(cur->bf == 1) {
                    rorateL(pare);
                }
                else {
                    rorateRL(pare);
                }
            }
            else {
                if(cur->bf == 1) {
                    rorateLR(pare);
                }
                else {
                    rorateR(pare);
                }
            }
            break;
        }
    }
}

int main() {
    while(~scanf("%d", &n)) {
        int data;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &data);
            insert(data);
        }
        if(n == 0)
            printf("%d\n", 0);
        else
            printf("%d\n", root->data);
    }
    return 0;
}