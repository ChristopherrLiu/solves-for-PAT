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
#define maxn 2010
#define maxe 250010
using namespace std;

struct Node {
    string name;
    int weight, totalWeight, num;
    int father;
};

int n, k, w, cnt;
int tree[maxn], totalWeight[maxn];
Node nodes[maxn];
string u, v;

map<string, int> name2id;
vector<pair<int, int>> relations;
vector<pair<string, int>> ans;

int getId(string name) {
    if(name2id[name] != 0) {
        int id = name2id[name];
        nodes[id].weight += w;
        nodes[id].totalWeight = nodes[id].weight;
        return id;
    }
    else {
        name2id[name] = ++cnt;
        nodes[cnt].name = name;
        nodes[cnt].weight += w;
        nodes[cnt].totalWeight = nodes[cnt].weight;
        nodes[cnt].num = 1;
        nodes[cnt].father = cnt;
        return cnt;
    }
}

int find(int p) {
    if(nodes[p].father == p)
        return p;
    else
        return nodes[p].father = find(nodes[p].father);
}

int main() {
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            cin >> u >> v >> w;
            int id1 = getId(u);
            int id2 = getId(v);
            relations.push_back(make_pair(id1, id2));
        }
        for(auto p : relations) {
            int f1 = find(p.first);
            int f2 = find(p.second);
            if(f1 == f2)
                continue;
            if(nodes[f1].weight < nodes[f2].weight) {
                nodes[f1].father = f2;
                nodes[f2].totalWeight += nodes[f1].totalWeight;
                nodes[f2].num += nodes[f1].num;
            } else  {
                nodes[f2].father = f1;
                nodes[f1].totalWeight += nodes[f2].totalWeight;
                nodes[f1].num += nodes[f2].num;
            }
        }
        for(int i = 1; i <= cnt; ++i) {
            if(nodes[i].father == i && nodes[i].totalWeight / 2 > k && nodes[i].num > 2) {
                ans.push_back(make_pair(nodes[i].name, nodes[i].num));
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for(auto p : ans) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}