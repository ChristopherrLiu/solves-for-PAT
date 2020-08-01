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

int n, d[maxn], pre[maxn], tail[maxn];
int m, a, b;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &d[i]);
            if(i > 1)
                pre[i] = pre[i - 1] + d[i - 1];
        }
        for(int i = n; i >= 1; --i) {
            tail[i] = tail[i + 1] + d[i];
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            if(a > b)
                swap(a, b);
            printf("%d\n", min(pre[b] - pre[a], pre[a] + tail[b]));
        }
    }
    return 0;
}