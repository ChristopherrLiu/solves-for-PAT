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
#define maxn 10010
#define maxe 51
using namespace std;

int n, m, k[maxe], a, b;
set<int> seqs[maxe];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &k[i]);
            for(int j = 0; j < k[i]; ++j) {
                scanf("%d", &a);
                seqs[i].insert(a);
            }
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            int nt = 0, nc = 0;
            set<int>::iterator pt1, pt2;
            pt1 = seqs[a].begin();
            pt2 = seqs[b].begin();
            while(pt1 != seqs[a].end() && pt2 != seqs[b].end()) {
                if(*pt1 < *pt2) {
                    ++nt;
                    ++pt1;
                }
                else if(*pt1 > *pt2) {
                    ++nt;
                    ++pt2;
                }
                else {
                    ++nt;
                    nc++;
                    ++pt1;
                    ++pt2;
                }
            }
            while(pt1 != seqs[a].end()) {
                ++pt1;
                ++nt;
            }
            while(pt2 != seqs[b].end()) {
                ++pt2;
                ++nt;
            }
            printf("%.1f%\n", (nc * 1.0 / nt) * 100);
        }
    }
    return 0;
}