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
#define maxe 300
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

ll Anum, Pnum, ans;
char strs[maxn];

int main() {
    while(~scanf("%s", strs)) {
        int len = strlen(strs);
        for(int i = 0; i < len; ++i) {
            if(strs[i] == 'P')
                Pnum++;
            else if(strs[i] == 'A') {
                Anum = (Anum + Pnum) % mod;
            }
            else {
                ans = (ans + Anum) % mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}