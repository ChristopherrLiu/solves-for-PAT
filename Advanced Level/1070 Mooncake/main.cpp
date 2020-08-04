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
#define maxe 110
using namespace std;

struct MoonCake {
    double inv;
    double unitPrice, value;
    bool operator< (const MoonCake& other) const {
        return unitPrice > other.unitPrice;
    }
};

int n, d;
MoonCake moonCakes[maxn];

int main() {
    while(~scanf("%d %d", &n, &d)) {
        for(int i = 0; i < n; ++i)
            scanf("%lf", &moonCakes[i].inv);
        for(int i = 0; i < n; ++i) {
            scanf("%lf", &moonCakes[i].value);
            moonCakes[i].unitPrice = moonCakes[i].value / moonCakes[i].inv;
        }
        
        double ans = 0;
        int cap = d;
        sort(moonCakes, moonCakes + n);
        for(int i = 0; i < n; ++i) {
            if(cap >= moonCakes[i].inv) {
                cap -= moonCakes[i].inv;
                ans += moonCakes[i].value;
            }
            else {
                ans += moonCakes[i].unitPrice * cap;
                cap = 0;
            }

            if(!cap)
                break;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}