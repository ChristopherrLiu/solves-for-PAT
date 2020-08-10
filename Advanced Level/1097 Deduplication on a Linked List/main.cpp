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
    int address, key;
};

int n, head, tot, address, tail[maxn], appear[maxn];
map<int, int>address2id;
vector<Node> originList, uniqueList, removeList;
Node nodes[maxn];

int main() {
    while(~scanf("%d %d", &head, &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &address);
            int id = address2id[address];
            if(id == 0)
                address2id[address] = id = ++tot;
            scanf("%d", &nodes[id].key);
            nodes[id].address = address;
            scanf("%d", &tail[id]);
        }
        int id = address2id[head];
        while(tail[id] != -1) {
            originList.push_back(nodes[id]);
            id = address2id[tail[id]];
        }
        originList.push_back(nodes[id]);
        for(auto node : originList) {
            if(appear[abs(node.key)] == 1) {
                removeList.push_back(node);
            }
            else {
                appear[(abs(node.key))] = 1;
                uniqueList.push_back(node);
            }
        }
        int sz = uniqueList.size();
        for(int i = 0; i < sz; ++i) {
            if(i > 0)
                printf("%05d\n", uniqueList[i].address);
            printf("%05d %d ", uniqueList[i].address, uniqueList[i].key);
            if(i == sz - 1)
                printf("-1\n");
        }
        sz = removeList.size();
        for(int i = 0; i < sz; ++i) {
            if(i > 0)
                printf("%05d\n", removeList[i].address);
            printf("%05d %d ", removeList[i].address, removeList[i].key);
            if(i == sz - 1)
                printf("-1\n");
        }
    }
    return 0;
}