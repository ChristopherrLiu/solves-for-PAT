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
#define maxe 1000000
using namespace std;

typedef long long ll;

int n, m, k, id1, id2, ids[maxn];
map<ll, bool> incompatible;
bool appear[maxe];

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &id1, &id2);
            if(id1 > id2)
                swap(id1, id2);
            incompatible[(ll)id1 * 100000 + (ll)id2] = true;
            appear[id1] = true;
            appear[id2] = true;
        }
        for(int i = 0; i < m; ++i) {
            bool flag = true;
            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &ids[j]);
                
            }
            for(int j = 0; j < k; ++j) {
                if(!appear[ids[j]])
                    continue;
                for(int l = j + 1; l < k; ++l) {
                    id1 = ids[j], id2 = ids[l];
                    if(!appear[ids[l]])
                        continue;
                    if(id1 > id2)
                        swap(id1, id2);
                    if(incompatible[(ll)id1 * 100000 + (ll)id2]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}