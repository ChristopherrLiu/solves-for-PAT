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
#define maxe 22
using namespace std;

int n, num[maxn];
set<int> pos;

int main() {
    while(~scanf("%d", &n)) {
        pos.clear();
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
            if(num[i] > 0)
                pos.insert(num[i]);
        }
        int pre = 1;
        bool flag = false;
        for(auto i : pos) {
            if(i > pre) {
                flag = true;
                ans = pre;
                break;
            }
            else if(i == pre) {
                pre++;
            }
        }
        if(!flag)
            ans = pre;
        printf("%d\n", ans);
    }
    return 0;
}