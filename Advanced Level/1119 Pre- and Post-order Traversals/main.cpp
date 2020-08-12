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
bool flag, first;

Node* restore(int le, int re, int lt, int rt) {
    // cout << le << " " << re << " " << lt << " " << rt << endl;
    Node* cur = new Node(preOrder[le]);
    if(le > re || lt > rt)
        return nullptr;
    if(le == re)
        return cur;
    int temp = preOrder[le + 1], mid = rt - 1;
    while(mid >= lt && postOrder[mid] != temp) {
        mid--;
    }

    int lsonNum = mid - lt + 1;
    int rsonNum = rt - mid - 1;

    if(rsonNum == 0) {
        flag = false;
    }

    cur->lson = restore(le + 1, le + lsonNum, lt, lt + lsonNum - 1);
    cur->rson = restore(le + lsonNum + 1, re, lt + lsonNum, rt - 1);

    return cur;
}

void inOrder(Node* cur) {
    if(!cur)
        return;
    inOrder(cur->lson);
    if(first)
        printf("%d", cur->key);
    else
        printf(" %d", cur->key);
    first = false;
    inOrder(cur->rson);
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &preOrder[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &postOrder[i]);
        flag = true;
        first = true;
        root = restore(0, n - 1, 0, n - 1);
        if(flag)
            puts("Yes");
        else
            puts("No");
        inOrder(root);
        printf("\n");
    }
    return 0;
}