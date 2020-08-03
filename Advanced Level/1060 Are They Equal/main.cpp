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
#define maxn 110
#define maxe 10
using namespace std;

int n, expa, expb;
char a[maxn], b[maxn], standA[maxn], standB[maxn];

void calExp(char *str, int flag) {
    int l = strlen(str);
    int i = 0;
    while(str[i] == '0')
        ++i;
    if(str[i] == '.') {
        ++i;
        for(; i < l && str[i] == '0'; ++i) {
            if(flag == 1)
                --expa;
            else
                --expb;
        }
        if(i == l) {
            if(flag == 1)
                expa = 0;
            else
                expb = 0;
        }
        return;
    }
    for(; i < l; ++i) {
        if(str[i] == '.')
            break;
        if(flag == 1)
            ++expa;
        else
            ++expb;
    }
}

void fill(char *dst, char *sour) {
    int l = strlen(sour), ps = 0;
    while(ps < l && (sour[ps] == '0' || sour[ps] == '.'))
        ++ps;
    for(int i = 0; i < n; ++i) {
        while(ps < l && sour[ps] == '.')
            ++ps;
        if(ps < l)
            dst[i] = sour[ps];
        else
            dst[i] = '0';
        ++ps;
    }
    dst[n] = 0;
}

int main() {
    while(~scanf("%d", &n)) {
        scanf("%s %s", a, b);
        calExp(a, 1);
        calExp(b, 2);
        fill(standA, a);
        fill(standB, b);
        // cout << standA << endl;
        // strncpy(standA, a, n);
        // strncpy(standB, b, n);
        if(strcmp(standA, standB) == 0 && expa == expb) {
            printf("YES 0.%s*10^%d\n", standA, expa);
        }
        else {
            printf("NO 0.%s*10^%d 0.%s*10^%d\n", standA, expa, standB, expb);
        }
    }
    return 0;
}