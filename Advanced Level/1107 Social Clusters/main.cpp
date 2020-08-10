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
#define maxe 110
using namespace std;

int n, k, u, clusterNum, cnt;
vector<int> edges[maxn];
bool vis[maxn];

void dfs(int cur) {
    if(cur <= n) {
        cnt++;
    }
    vis[cur] = true;
    for(auto next : edges[cur]) {
        if(!vis[next])
            dfs(next);
    }
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d:", &k);
            for(int j = 1; j <= k; ++j) {
                scanf("%d", &u);
                edges[i].push_back(u + n);
                edges[u + n].push_back(i);
            }
        }
        vector<int> nums;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                clusterNum++;
                cnt = 0;
                dfs(i);
                nums.push_back(cnt);
            }
        }
        sort(nums.begin(), nums.end());
        printf("%d\n", clusterNum);
        for(int i = nums.size() - 1; i >= 0; --i)
            printf("%d%c", nums[i], i == 0 ? '\n' : ' ');
    }
    return 0;
}