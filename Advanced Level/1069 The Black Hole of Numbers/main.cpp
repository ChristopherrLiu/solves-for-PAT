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
#define maxn 10
#define maxe 110
using namespace std;

int num;
char n[maxn], a[maxn], b[maxn];

bool cmp(const char& a, const char& b) {
    return a > b;
}

int main() {
    while(~scanf("%d", &num)) {
        sprintf(n, "%04d", num);
        do {
            strcpy(a, n);
            strcpy(b, n);
            sort(a, a + 4);
            sort(b, b + 4, cmp);
            int carry = 0, cur;
            for(int i = 3; i >= 0; --i) {
                if(b[i] - carry < a[i])
                    cur = b[i] + 10 - a[i] - carry, carry = 1;
                else
                    cur = b[i] - a[i] - carry, carry = 0;
                n[i] = cur + '0';
            }
            printf("%s - %s = %s\n", b, a, n);
        }while(strcmp(n, "0000") && strcmp(n, "6174"));
    }
    return 0;
}