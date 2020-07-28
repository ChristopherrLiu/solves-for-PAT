#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;

int n,requestList[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &requestList[i]);
        int ans = 0, currentFloor = 0, base;
        for(int i = 0; i < n; ++i) {
            if(requestList[i] == currentFloor) {
                ans += 5;
                continue;
            }
            base = requestList[i] > currentFloor ? 6 : 4;
            ans += (5 + base * abs(requestList[i] - currentFloor));
            currentFloor = requestList[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}