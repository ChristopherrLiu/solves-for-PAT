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
#define maxe 10
using namespace std;

int n, preOrder[maxn], postOrder[maxn];

struct Node {
    int key;
    Node* lson;
    Node* rson;
    Node(int key_) {
        key = key_, lson = nullptr, rson = nullptr;
    }
};

Node* root;

Node* restore(int le, int re, int lt, int rt) {
    Node* cur = new Node(preOrder[le]);
    if(le == re)
        return cur;
    int leRoot = preOrder[le + 1], ltRoot = rt - 1;
    while(ltRoot >= lt && postOrder[ltRoot] != leRoot) {
        ltRoot--;
    }
    
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &preOrder[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &postOrder[i]);
    }
    return 0;
}