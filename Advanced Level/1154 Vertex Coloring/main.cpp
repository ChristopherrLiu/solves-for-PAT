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
#define maxe 1010
#define DEBUG
using namespace std;

int n, m, u, v, q;
int colors[maxn];
set<int> ncolor;
vector<pair<int, int> >adj;
bool flag;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        if(u > v)
            swap(u, v);
        adj.push_back(make_pair(u, v));
    }
    
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        ncolor.clear();
        flag = true;
        for(int j = 0; j < n; ++j) {
           scanf("%d", &colors[j]);
            ncolor.insert(colors[j]);
        }
        for(int j = 0; j < m; ++j) {
            if(colors[adj[j].first] == colors[adj[j].second]) {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("%d-coloring\n", ncolor.size());
        else
            puts("No");
    }

    #ifdef DEBUG
    getchar();
    getchar();
    #endif 
    return 0;
}