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
#define maxe 11
using namespace std;

int n;
int seq[maxn], idx[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &seq[i]);
            idx[seq[i]] = i;
        }
        int cnt = 0, ans = 0, tag = idx[0];
        for(int i = 1; i < n; ++i) {
            if(i != idx[i]) {
                while(idx[0] != 0) {
                    swap(idx[0], idx[idx[0]]);
                    ans++;
                }
                if(i != idx[i]) {
                    swap(idx[0], idx[i]);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}