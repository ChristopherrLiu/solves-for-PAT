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
#define maxn 100010
#define maxe 22
using namespace std;


struct Node {
    int key, address, next;
};

int head, n, k;
map<int, int>address2id;
vector<Node> origin, neg, bk, uk;
Node nodes[maxn];

int main() {
    while(~scanf("%d %d %d", &head, &n, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d", &nodes[i].address, &nodes[i].key ,&nodes[i].next);
            address2id[nodes[i].address] = i;
        }
        int pt = address2id[head];
        while(nodes[pt].next != -1) {
            origin.push_back(nodes[pt]);
            pt = address2id[nodes[pt].next];
        }
        origin.push_back(nodes[pt]);

        for(auto node : origin) {
            if(node.key < 0)
                neg.push_back(node);
            else if(node.key <= k)
                bk.push_back(node);
            else
                uk.push_back(node);
        }
        int sum = 0;
        for(int i = 0; i < neg.size(); ++i, ++sum) {
            if(sum == 0)
                printf("%05d %d", neg[i].address, neg[i].key);
            else {
                printf(" %05d\n", neg[i].address);
                printf("%05d %d", neg[i].address, neg[i].key);
            }
        }
        for(int i = 0; i < bk.size(); ++i, ++sum) {
            if(sum == 0)
                printf("%05d %d", bk[i].address, bk[i].key);
            else {
                printf(" %05d\n", bk[i].address);
                printf("%05d %d", bk[i].address, bk[i].key);
            }
        }
        for(int i = 0; i < uk.size(); ++i, ++sum) {
            if(sum == 0)
                printf("%05d %d", uk[i].address, uk[i].key);
            else {
                printf(" %05d\n", uk[i].address);
                printf("%05d %d", uk[i].address, uk[i].key);
            }
        }
        printf(" -1\n");
    }
    return 0;
}