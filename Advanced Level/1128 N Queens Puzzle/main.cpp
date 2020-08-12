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
#define maxn 2010
#define maxe 22
using namespace std;

int k, n, rows[maxn];
bool sameRow[maxn], diagonal[maxn];

int main() {
    while(~scanf("%d", &k)) {
        for(int i = 0; i < k; ++i) {
            scanf("%d", &n);
            for(int j = 0 ; j < n; ++j) 
                scanf("%d", &rows[j]);
            bool flag = true;
            memset(sameRow, false, sizeof(sameRow));
            memset(diagonal, false, sizeof(diagonal));
            for(int j = 0; j < n; ++j) {
                if(sameRow[rows[j]]) {
                    flag = false;
                    break;
                }
                else {
                    sameRow[rows[j]] = true;
                    if(diagonal[rows[j] - j - 1 + n]) {
                        flag = false;
                        break;
                    }
                    else {
                        diagonal[rows[j] - j - 1 + n] = true;
                    }
                }
            }
            if(flag)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}