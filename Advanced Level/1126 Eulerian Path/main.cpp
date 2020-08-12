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
#define maxe 22
using namespace std;

int n, m, u, v, even, odd;
int degrees[maxn], father[maxn];

int find(int r) {
    return father[r] == -1 ? r : father[r] = find(father[r]);
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        memset(father, -1, sizeof(father));
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            degrees[u]++;
            degrees[v]++;
            int fu = find(u);
            int fv = find(v);
            if(fu != fv)
                father[fu] = fv;
        }
        int ff = 0;
        for(int i = 1; i <= n; ++i)
            if(father[i] == -1)
                ff++;
        for(int i = 1; i <= n; ++i)
            if(degrees[i] % 2)
                odd++;
            else
                even++;
        for(int i = 1; i <= n; ++i)
            printf("%d%c", degrees[i], i == n ? '\n' : ' ');
        if(ff > 1)
            puts("Non-Eulerian");
        else if(even == n)
            puts("Eulerian");
        else if(odd == 2 && even == n - 2)
            puts("Semi-Eulerian");
        else
            puts("Non-Eulerian");
    }
    return 0;
}