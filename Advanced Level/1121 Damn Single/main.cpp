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
#define maxe 10
using namespace std;

int n , m, ids[maxn], u, v, cnt, singles[maxn];
map<int, int> couple, appear;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);
            ++u, ++v;
            couple[u] = v;
            couple[v] = u;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", &ids[i]);
            appear[ids[i]] = 1;
            if(couple[ids[i] + 1] == 0)
                singles[cnt++] = ids[i];
        }
        for(int i = 0; i < m; ++i)
            if(couple[ids[i] + 1] && appear[couple[ids[i] + 1] - 1] == 0)
                singles[cnt++] = ids[i];
        sort(singles, singles + cnt);
        printf("%d\n", cnt);
        for(int i = 0 ; i < cnt; ++i)
            printf("%05d%c", singles[i], i == cnt - 1 ? '\n' : ' ');
    }
    return 0;
}