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
#define maxe 10
using namespace std;

int m, n, num, tag, freq;

int main() {
    while(~scanf("%d %d", &m, &n)) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &num);
                if(freq == 0)
                    tag = num, freq = 1;
                else {
                    if(tag != num)
                        --freq;
                    else
                        freq++;
                }
            }
        }
        printf("%d\n", tag);
    }
    return 0;
}