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
#define maxn 100010
#define maxe 10010
using namespace std;

int n, m;
int d[maxn];
vector<pair<int, int> >ans;

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &d[i]);
        int l = 0, r = 0, sum = d[0], tag = 1e9;
        while(l < n) {
            if(sum >= m && sum - m < tag) {
                tag = sum - m;
                ans.clear();
                ans.push_back(make_pair(l + 1, r + 1));
            }
            else if(sum >= m && sum - m == tag) {
                ans.push_back(make_pair(l + 1, r + 1));
            }

            if(r == n - 1) {
                if(sum < m)
                    break;
                else
                    sum -= d[l++];
                continue;
            }

            if(l == r) {
                sum += d[++r];
            }
            else {
                if(sum >= m) {
                    sum -= d[l++];
                }
                else {
                    sum += d[++r];
                }
            }
        }
        for(auto p : ans) {
            printf("%d-%d\n", p.first, p.second);
        }
    }
    return 0;
}