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
#define maxe 250010
using namespace std;

int nc, np, ans;
int coupon[maxn], product[maxn];

int main() {
    while(~scanf("%d", &nc)) {
        for(int i = 0; i < nc; ++i) {
            scanf("%d", &coupon[i]);
        }
        scanf("%d", &np);
        for(int j = 0; j < np; ++j) {
            scanf("%d", &product[j]);
        }
        sort(coupon, coupon + nc);
        sort(product, product + np);
        int pc = nc - 1, pp = np - 1;
        // cout << coupon[3] << " " << coupon[2] << endl;
        while(coupon[pc] > 0 && product[pp] > 0) {
            ans += coupon[pc] * product[pp];
            --pc, --pp;
        }
        pc = 0, pp = 0;
        while(coupon[pc] < 0 && product[pp] < 0) {
            ans += coupon[pc] * product[pp];
            ++pc, ++pp;
        }
        printf("%d\n", ans);
    }
    return 0;
}