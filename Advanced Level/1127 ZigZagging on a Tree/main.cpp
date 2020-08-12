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

int n, inOrder[maxn], postOrder[maxn], deepNodes[maxe][maxn], deepNums[maxn];

struct Node {
    int key;
    Node* lson;
    Node* rson;
    Node(int k_) : key(k_), lson(nullptr), rson(nullptr) {}
};

Node* root;

Node* restore(int il, int ir, int pl, int pr) {
    if(il > ir) {
        return nullptr;
    }
    else if(il == ir) {
        Node* cur = new Node(inOrder[il]);
        return cur;
    }
    else {
        int rootKey = postOrder[pr];
        int mid = il;
        while(inOrder[mid] != rootKey)
            ++mid;
        
        Node* cur = new Node(rootKey);
        cur->lson = restore(il, mid - 1, pl, pl + mid - il - 1);
        cur->rson = restore(mid + 1, ir, pl + mid - il, pr - 1);
        return cur;
    }
} 

void bfs() {
    queue<pair<Node*, int> >que;
    que.push(make_pair(root, 0));
    while(que.size()) {
        pair<Node*, int> t = que.front();
        que.pop();
        deepNodes[t.second][deepNums[t.second]++] = t.first->key;
        if(t.first->lson)
            que.push(make_pair(t.first->lson, t.second + 1));
        if(t.first->rson)
            que.push(make_pair(t.first->rson, t.second + 1));
    }
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &inOrder[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &postOrder[i]);
        root = restore(0, n - 1, 0, n - 1);
        bfs();
        int deepPt = 0;
        while(deepNums[deepPt]) {
            if(deepPt % 2) {
                for(int i = 0; i < deepNums[deepPt]; ++i)
                    printf(" %d", deepNodes[deepPt][i]);
            }
            else {
                if(deepPt == 0)
                    printf("%d", deepNodes[deepPt][0]);
                else {
                    for(int i = deepNums[deepPt] - 1; i >= 0; --i)
                        printf(" %d", deepNodes[deepPt][i]);
                }
            }
            deepPt++;
        }
        printf("\n");
    }
    return 0;
}