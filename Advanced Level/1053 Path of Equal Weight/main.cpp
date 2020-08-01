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
#define maxe 257
using namespace std;

struct Path {
    string tag;
    vector<int> path;
    bool operator< (const Path other) const {
        return tag > other.tag;
    }
};

int n, m, s, id, k, c, cnt;
int weight[maxn];
vector<int> son[maxn], path;
string strPath;
Path paths[maxn];

void dfs(int id, int curSum, string tag) {
    path.push_back(weight[id]);
    curSum += weight[id];
    stringstream ss;
    char temp[4];
    sprintf(temp, "%04d", weight[id]);
    tag = tag + temp;
    if(curSum == s && son[id].size() == 0) {
        paths[cnt].tag = tag;
        paths[cnt].path = path;
        ++cnt;
    }
    for(auto next : son[id]) {
        dfs(next, curSum, tag);
    }
    path.pop_back();
}

int main() {
    while(~scanf("%d %d %d", &n, &m, &s)) {
        for(int i = 0; i< n; ++i)
            scanf("%d", &weight[i]);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &id, &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &c);
                son[id].push_back(c);
            }
        }
        dfs(0, 0, "");
        sort(paths, paths + cnt);
        for(int i = 0; i < cnt; ++i) {
            printf("%d", paths[i].path[0]);
            for(int j = 1; j < paths[i].path.size(); ++j)
                printf(" %d", paths[i].path[j]);
            printf("\n");
        }
    }
    return 0;
}