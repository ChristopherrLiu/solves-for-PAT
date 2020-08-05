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
#define maxe 15
using namespace std;

struct Node {
    int id, data, next;
};

int head, n, k, id;
Node nodes[maxn];
map<int, int> id2id;
vector<Node> linkedList;

int main() {
    while(~scanf("%d %d %d", &head, &n, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &nodes[i].id);
            scanf("%d %d", &nodes[i].data, &nodes[i].next);
            id2id[nodes[i].id] = i;
        }
        id = id2id[head];
        while(nodes[id].next != -1) {
            linkedList.push_back(nodes[id]);
            id = id2id[nodes[id].next];
        }
        linkedList.push_back(nodes[id]);
        int sz = linkedList.size();
        for(int i = 0; i < sz; i += k) {
            if(i + k > sz) {
                for(int j = i; j < sz; ++j) {
                    printf("%05d\n", linkedList[j].id);
                    printf("%05d %d ", linkedList[j].id, linkedList[j].data);
                }
            }
            else {
                for(int j = i + k - 1; j >= i; --j) {
                    if(j != k - 1)
                        printf("%05d\n", linkedList[j].id);
                    printf("%05d %d ", linkedList[j].id, linkedList[j].data);
                }
            }
        }
        if(sz)
            printf("-1\n");
    }
    return 0;
}