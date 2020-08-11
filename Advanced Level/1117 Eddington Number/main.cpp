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
#define maxe 2
using namespace std;

int n, ans, seq[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &seq[i]);
        sort(seq, seq + n);
        for(int l = 0; l < n; ++l) {
            if(n - l < seq[l]) {
                ans = n - l;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}