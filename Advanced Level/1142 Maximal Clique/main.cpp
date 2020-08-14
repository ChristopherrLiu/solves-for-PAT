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
#define maxn 210
#define maxe 22
using namespace std;

int nv, ne, q, k, u, v;
int sets[maxn], edges[maxn][maxn];
vector<int> adj[maxn];

int main() {
    while(~scanf("%d %d", &nv, &ne)) {
        for(int i = 0; i < ne; ++i) {
            scanf("%d %d", &u, &v);
            edges[u][v] = edges[v][u] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        scanf("%d", &q);
        for(int i = 0; i < q; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j)
                scanf("%d", &sets[j]);
            bool flag = true, ismax = true;
            for(int j = 0; j < k; ++j)
                for(int l = j + 1; l < k; ++l) {
                    if(!edges[sets[j]][sets[l]]) {
                        flag = false;
                        ismax = false;
                        break;
                    }
                }
            if(flag && k) {
                for(auto a : adj[sets[0]]) {
                    bool all = true;
                    for(int j = 1; j < k; ++j) {
                        if(!edges[a][sets[j]]) {
                            all = false;
                        }
                    }
                    if(all) {
                        ismax = false;
                        break;
                    }
                }
            }
            if(!flag) {
                puts("Not a Clique");
            }
            else if(!ismax) {
                puts("Not Maximal");
            }
            else {
                puts("Yes");
            }
        }
    }
    return 0;
}