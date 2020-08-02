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
#define maxn 1010
#define maxe 10
using namespace std;

int np, ng, r;
int ids[maxn], ranks[maxn], weight[maxn];
vector<int> mices;
bool vis[maxn];

void solve(vector<int> m) {
    int Len = m.size();
    vector<int> nextm;
    for(int i = 0; i < Len; i += ng) {
        int tag = -1, idx;
        for(int j = 0; j < ng; ++j) {
            if(i + j >= Len)
                continue;
            if(weight[m[i + j]] > tag) {
                tag = weight[m[i + j]];
                idx = m[i + j];
            }
        }
        nextm.push_back(idx);
    }
    if(nextm.size() > 1)
        solve(nextm);
    else {
        for(auto p : nextm) {
            ranks[p] = ++r;
            vis[p] = true;
            ++r;
        }
    }
    for(auto p : m) {
        if(vis[p])
            continue;
        ranks[p] = r;
        vis[p] = true;
    }
    r = m.size() + 1;
}   

int main() {
    while(~scanf("%d %d", &np, &ng)) {
        for(int i = 0; i < np; ++i) {
            scanf("%d", &weight[i]);
        }
        for(int i = 0; i < np; ++i) {
            scanf("%d", &ids[i]);
            mices.push_back(ids[i]);
        }
        solve(mices);
        for(int i = 0; i < np; ++i) {
            printf("%d%c", ranks[i], i == np - 1 ? '\n' : ' ');
        }
    }
    return 0;
}