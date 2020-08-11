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
#define maxn 10010
#define maxe 2
using namespace std;

struct Family {
    int id, num, area, setNum;
    bool operator< (const Family other) const {
        return (area * 1.0 / num != other.area * 1.0 / other.num) ? (area * 1.0 / num > other.area * 1.0 / other.num) : (
            id != other.id ? id < other.id : false
        );
    }
}familys[maxn];

int n, id, fa, ch, k, cnt, tot, ids[maxn], sets[maxn], areas[maxn];
vector<int> edges[maxn];
map<int, int> id2id;
bool vis[maxn];

void dfs(int cur) {
    if(areas[cur]) {
        familys[tot].area += areas[cur];
        familys[tot].setNum += sets[cur];
    }
    familys[tot].num += 1;
    familys[tot].id = min(familys[tot].id, ids[cur]);
    vis[cur] = true;
    for(auto next : edges[cur]) {
        if(!vis[next])
            dfs(next);
    }
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &id);
            int realId = id2id[id];
            if(realId == 0)
                realId = id2id[id] = ++cnt;
            ids[realId] = id;
            scanf("%d", &fa);
            if(fa != -1) {
                int realfId = id2id[fa];
                if(realfId == 0)
                    realfId = id2id[fa] = ++cnt;
                ids[realfId] = fa;
                edges[realfId].push_back(realId);
                edges[realId].push_back(realfId);
            }
            scanf("%d", &fa);
            if(fa != -1) {
                int realfId = id2id[fa];
                if(realfId == 0)
                    realfId = id2id[fa] = ++cnt;
                ids[realfId] = fa;
                edges[realfId].push_back(realId);
                edges[realId].push_back(realfId);
            }

            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &ch);
                int realfId = id2id[ch];
                if(realfId == 0)
                    realfId = id2id[ch] = ++cnt;
                ids[realfId] = ch;
                edges[realId].push_back(realfId);
                edges[realfId].push_back(realId);
            }
            scanf("%d", &sets[realId]);
            scanf("%d", &areas[realId]);
        }
        for(int i = 1; i <= cnt; ++i) {
            if(!vis[i]) {
                familys[tot].id = 1e5;
                dfs(i);
                tot++;
            }
        }
        sort(familys, familys + tot);
        printf("%d\n", tot);
        for(int i = 0; i < tot; ++i) {
            printf("%04d %d %.3f %.3f\n", familys[i].id, familys[i].num, familys[i].setNum * 1.0 / familys[i].num, familys[i].area * 1.0 / familys[i].num);
        }
    }
    return 0;
}