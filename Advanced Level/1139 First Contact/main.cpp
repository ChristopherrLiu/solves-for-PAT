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
#define maxe 22
using namespace std;

int n, m, k, u, v;
map<int, int> edges;
vector<int> friends[maxn];

struct Pair {
    int a, b;
    Pair(int a_, int b_) {
        a = a_, b = b_;
    }
    bool operator< (const Pair other) const {
        return a != other.a ? a < other.a : (
            b != other.b ? b < other.b : false
        );
    }
};

int  main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            if(u * v > 0) {
                friends[abs(u)].push_back(abs(v));
                friends[abs(v)].push_back(abs(u));
            } 
            edges[abs(u) * 10000 + abs(v)] = edges[abs(v) * 10000 + abs(u)] = 1;
        }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &u, &v);
            vector<Pair >ans;
            int f1, f2;
            for(int j = 0; j < friends[abs(u)].size(); ++j) {
                f1 = friends[abs(u)][j]; 
                if(f1 == abs(v))
                    continue;
                for(int p = 0; p < friends[abs(v)].size(); ++p) {
                    f2 = friends[abs(v)][p];
                    if(f2 == abs(u))
                        continue;
                    if(edges[f1 * 10000 + f2]) {
                        ans.push_back(Pair(f1, f2));
                    }
                }
            }
            sort(ans.begin(), ans.end());
            printf("%d\n", ans.size());
            for(auto t : ans) {
                printf("%04d %04d\n", t.a, t.b);
            }
        }
    }
    return 0;
}