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
#define maxn 200010
#define maxe 110
using namespace std;

int n, m, s1[maxn], s2[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &s1[i]);
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
            scanf("%d", &s2[i]);
        int mid = (int)round((n + m) * 1.0 / 2);
        int ans, pt = 0, pt1 = 0, pt2 = 0;
        while(pt1 < n && pt2 < m) {
            if(s1[pt1] < s2[pt2])
                ans = s1[pt1++];
            else
                ans = s2[pt2++];
            ++pt;
            if(pt == mid)
                break;
        }
        if(pt == mid)
            cout << ans << "\n";
        else {
            if(pt1 < n) {
                while(pt1 < n) {
                    ans = s1[pt1++];
                    ++pt;
                    if(pt == mid)
                        break;
                }
                cout << ans << "\n";
            }
            else {
                while(pt2 < m) {
                    ans = s2[pt2++];
                    ++pt;
                    if(pt == mid)
                        break;
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}