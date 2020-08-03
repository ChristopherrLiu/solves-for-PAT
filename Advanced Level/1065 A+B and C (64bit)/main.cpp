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
#define maxe 11
using namespace std;

int n;
long long a, b, c;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lld %lld %lld", &a, &b, &c);
            printf("Case #%d: ", i + 1);
            if(a > 0 && b > 0) {
                if(c < 0)
                    printf("true\n");
                else if(a > c - b)
                    printf("true\n");
                else
                    printf("false\n");
            }
            else if(a < 0 && b < 0) {
                if(c >= 0)
                    printf("false\n");
                else if(a > c - b)
                    printf("true\n");
                else
                    printf("false\n");
            }
            else {
                if(a + b > c)
                    printf("true\n");
                else
                    printf("false\n");
            }
        }
    }
    return 0;
}