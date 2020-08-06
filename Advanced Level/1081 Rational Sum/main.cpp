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
#define maxe 110
#define maxk 6
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long Abs(long long a) {
    return a < 0 ? -a : a;
}

struct RationalNumber {
    long long inter, num, deno;
    RationalNumber operator+ (const RationalNumber other) const {
        RationalNumber res;
        long long multiple = deno * other.deno / gcd(deno, other.deno);
        res.num = num * (multiple / deno) + other.num * (multiple / other.deno);
        res.deno = multiple;
        res.inter = inter + other.inter;
        res.inter += res.num / res.deno;
        res.num %= res.deno;
        long long _gcd = gcd(Abs(res.num), res.deno);
        res.num /= _gcd;
        res.deno /= _gcd;
        // cout << res.num << " " << res.deno << endl;
        return res;
    }
};

int n, cnt;
char strRN[maxe], num[maxe];
RationalNumber rn[maxn], ans;

int main() {
    ans.deno = ans.num = ans.inter = 0;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", strRN);
            int Len = strlen(strRN);
            int j = 0, flag = 1;
            if(strRN[i] == '-')
                flag = -1, ++j;
            cnt = 0;
            for(; strRN[j] != '/'; ++j)
                num[cnt++] = strRN[j];
            num[cnt] = 0;
            sscanf(num, "%lld", &rn[i].num);
            rn[i].num *= flag;
            cnt = 0;
            for(++j; j < Len; ++j) 
                num[cnt++] = strRN[j];
            num[cnt] = 0;
            sscanf(num, "%lld", &rn[i].deno);
            rn[i].inter = 0;
            if(i == 0)
                ans = rn[i];
            else
                ans = ans + rn[i];
        }
        if(ans.inter)
            printf("%lld%c", ans.num ? Abs(ans.inter) : ans.inter, ans.num == 0 ? '\n' : ' ');
        if(ans.num)
            printf("%lld/%lld\n", ans.num, ans.deno);
        if(ans.inter == 0 && ans.num == 0)
            printf("0\n");
    }
    return 0;
}