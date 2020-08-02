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
#define maxe 10
using namespace std;

struct Node {
    int id, key, next;
    bool operator< (const Node other) const {
        return key < other.key;
    }
};

int n, head, id;
Node nodes[maxn];
vector<Node> validNodes;

int main() {
    while(~scanf("%d %d", &n, &head)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &id);
            nodes[id].id = id;
            scanf("%d %d", &nodes[id].key, &nodes[id].next);
        }
        for(int i = head; i != -1; i = nodes[i].next) {
            validNodes.push_back(nodes[i]);
        }
        if(validNodes.size() == 0) {
            puts("0 -1");
            continue;
        }
        sort(validNodes.begin(), validNodes.end());
        printf("%d %05d\n", validNodes.size(), validNodes[0].id);
        int cnt = 0;
        for(auto node : validNodes) {
            printf("%05d %d ", node.id, node.key);
            if(cnt != validNodes.size() - 1)
                printf("%05d\n", validNodes[cnt + 1].id);
            else
                printf("%d\n", -1);
            cnt++;
        }
    }
    return 0;
}