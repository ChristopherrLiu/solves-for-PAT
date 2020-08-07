#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 100010
#define maxe 85
#define maxk 10
using namespace std;

struct Node {
    int data;
    Node* lson;
    Node* rson;
    Node(int d) :
        data(d),
        lson(nullptr),
        rson(nullptr)
    {}
};

int n, cc, d[maxn];
char opt[maxn][maxk];
Node* root;

Node* getInorder() {
    if(strcmp(opt[cc], "Push") == 0) {
        Node* cur = new Node(d[cc]);
        ++cc;
        cur->lson = getInorder();
        ++cc;
        cur->rson = getInorder();
        return cur;
    }
    else {
        // ++cc;
        return nullptr;
    }
}

void dfs(Node *cur) {
    if(cur) {
        dfs(cur->lson);
        dfs(cur->rson);
        printf("%d%c", cur->data, cur == root ? '\n' : ' ');
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; ++i) {
        getchar();
        scanf("%s", opt[i]);
        if(strcmp(opt[i], "Push") == 0)
            scanf("%d", &d[i]);
    }
    strcpy(opt[2 * n], "Pop");
    root = getInorder();
    dfs(root);
    getchar();
    getchar();
    return 0;
}