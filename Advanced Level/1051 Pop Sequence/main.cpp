#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 1010
#define maxe 257
using namespace std;

int m, n, k, seq[maxn];
stack<int> sta;

int main() {
    while(~scanf("%d %d %d", &m, &n, &k)) {
        for(int i = 0; i < k; ++i) {
            for(int i = 0; i < n; ++i) {
                scanf("%d", &seq[i]);
            }
            int curElement = 1, curPt = 0;
            while(curElement <= n && curPt < n) {
                if(sta.size() == 0)
                    sta.push(curElement++);
                while(curElement <= n && sta.size() <= m && seq[curPt] != sta.top())
                    sta.push(curElement++);
                // cout << sta.size() << endl;
                if(sta.size() > m)
                    break;
                while(curPt < n && sta.size() && seq[curPt] == sta.top()) {
                    sta.pop();
                    curPt++;
                }
            }
            if(curPt != n || curElement != n + 1)
                puts("NO");
            else
                puts("YES");
            while(sta.size())
                sta.pop();
        }
    }
    return 0;
}