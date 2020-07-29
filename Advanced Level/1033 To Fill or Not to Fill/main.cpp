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
#define maxn 510
#define maxe 250010
using namespace std;

struct GasStation {
    double price, dis;
    bool operator< (const GasStation other) const {
        return dis != other.dis ? dis < other.dis : (price != other.price ? price < other.price : false);
    }
};

int n;
double cmax, d, dPerGas;
GasStation gasStation[maxn];

int main() {
    while(~scanf("%lf %lf %lf %d", &cmax, &d, &dPerGas, &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &gasStation[i].price, &gasStation[i].dis);
        }
        n += 1;
        gasStation[n - 1].price = 0;
        gasStation[n - 1].dis = d;
        sort(gasStation, gasStation + n);
        double curGas = 0, ans = 0;
        if(gasStation[0].dis != 0) {
            printf("The maximum travel distance = 0.00\n");
            continue;
        }
        else {
            int gsId = 0;
            bool canReach = false, getLess = false;
            while(gsId < n - 1) {
                canReach = false, getLess = false;
                double tag = 1e9;
                int temp = gsId + 1, nextId;
                while(temp < n && gasStation[temp].dis <= gasStation[gsId].dis + cmax * dPerGas) {
                    canReach = true;
                    if(gasStation[temp].price < gasStation[gsId].price) {
                        getLess = true;
                        nextId = temp;
                        break;
                    }
                    if(gasStation[temp].price < tag) {
                        tag = gasStation[temp].price;
                        nextId = temp;
                    }
                    ++temp;
                }
                if(canReach == false) {
                    printf("The maximum travel distance = %.2f\n", gasStation[gsId].dis + cmax * dPerGas);
                    break;
                }
                else {
                    if(getLess) {
                        double needGas = ((gasStation[nextId].dis - gasStation[gsId].dis) / dPerGas) - curGas;
                        if(needGas < 0)
                            needGas = 0;
                        curGas = curGas + needGas - ((gasStation[nextId].dis - gasStation[gsId].dis) / dPerGas);
                        ans += needGas * gasStation[gsId].price;
                        gsId = nextId;
                    }
                    else {
                        ans += (cmax - curGas) * gasStation[gsId].price;
                        curGas = cmax - ((gasStation[nextId].dis - gasStation[gsId].dis) / dPerGas);
                        gsId = nextId;
                    }
                }
                // cout << gsId << " " << ans << endl;
            }
            if(canReach)
                printf("%.2f\n", ans);
        }
    }
    return 0;
}