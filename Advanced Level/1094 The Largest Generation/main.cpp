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
#define maxe 300
using namespace std;

int n, m, u, v, k, nums[maxn], ans, tag;
vector<int> sons[maxn];

void dfs(int cur, int deep) {
    nums[deep]++;
    if(nums[deep] > tag) {
        tag = nums[deep];
        ans = deep;
    }
    for(auto next : sons[cur]) {
        dfs(next, deep + 1);
    }
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &v);
                sons[u].push_back(v);
            }
        }
        dfs(1, 1);
        printf("%d %d\n", tag, ans);
    }
    return 0;
}