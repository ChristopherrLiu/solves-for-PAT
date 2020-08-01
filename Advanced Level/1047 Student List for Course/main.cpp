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
#define maxn 2510
#define maxe 257
using namespace std;

int n, m;
int id, k;
vector<char*> cour[maxn];

bool cmp(char *a, char *b) {
    for(int i = 0; i < 4; ++i) {
        if(a[i] < b[i])
            return true;
        else if(a[i] > b[i])
            return false;
    }
    return true;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            char *name = new char[4];
            scanf("%s", name);
            scanf("%d", &k);
            for(int i = 0; i < k; ++i) {
                scanf("%d", &id);
                cour[id].push_back(name);
            }
        }
        for(int i = 1; i <= m; ++i) {
            printf("%d %d\n", i, cour[i].size());
            sort(cour[i].begin(), cour[i].end(), cmp);
            for(auto s : cour[i])
                printf("%s\n", s);
        }
    }
    return 0;
}