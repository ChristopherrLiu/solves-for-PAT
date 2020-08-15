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
#define maxe 22
using namespace std;

int n, m, q, k, u, v, sets[maxn], temp[maxn], degree[maxn];
vector<int> edges[maxn];

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            // degree[u]++;
            degree[v]++;
            edges[u].push_back(v);
        }
        scanf("%d", &q);
        vector<int> ans;
        for(int i = 0; i < q; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &sets[j]);
            }
            memcpy(temp, degree, sizeof(degree));
            bool flag = true;
            for(int j = 0; j < n; ++j) {
                if(temp[sets[j]]) {
                    flag = false;
                    break;
                }
                else {
                    for(auto ne : edges[sets[j]])
                        temp[ne]--;
                }
            }
            if(!flag)
                ans.push_back(i);
        }
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}