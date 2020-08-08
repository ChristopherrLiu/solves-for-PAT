#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 1300
#define maxe 130
#define maxk 65
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
} 

ll Abs(ll a) {
    return a < 0 ? -a : a;
}

struct RationalNumber {
    ll integer, num, deno;
    void simple() {
        integer += num / deno;
        num %= deno;
        ll g = gcd(Abs(num), deno);
        num /= g;
        deno /= g;
    }
    void print() {
        if(integer < 0) {
            if(num)
                printf("(%lld %lld/%lld)", integer, Abs(num), deno);
            else
                printf("(%lld)", integer);
        }
        else if(integer == 0) {
            if(num < 0)
                printf("(%lld/%lld)", num, deno);
            else if(num > 0)
                printf("%lld/%lld", num, deno);
            else
                printf("0");
        }
        else {
            if(num)
                printf("%lld %lld/%lld", integer, num, deno);
            else
                printf("%lld", integer);
        }
    }
    RationalNumber operator+(const RationalNumber other) {
        RationalNumber res;
        res.integer = integer + other.integer;
        ll g = gcd(deno, other.deno);
        ll mul = deno * other.deno / g;
        res.num = num * (mul / deno) + other.num * (mul / other.deno);
        res.deno = mul;
        res.simple();
        return res;
    }
    RationalNumber operator-(const RationalNumber other) {
        RationalNumber res;
        res.integer = integer - other.integer;
        ll g = gcd(deno, other.deno);
        ll mul = deno * other.deno / g;
        res.num = num * (mul / deno) - other.num * (mul / other.deno);
        res.deno = mul;
        res.simple();
        return res;
    }
    RationalNumber operator*(const RationalNumber other) {
        RationalNumber res;
        res.integer = 0;
        res.num = num  * other.num;
        res.deno = deno * other.deno;
        if(res.deno < 0)
            res.deno *= -1, res.num *= -1;
        res.simple();
        return res;
    }
    RationalNumber operator/(const RationalNumber other) {
        RationalNumber res;
        if(other.num == 0 && integer == 0)
            return res;
        res.integer = 0;
        res.num = num  * other.deno;
        res.deno = deno * other.num;
        if(res.deno < 0)
            res.deno *= -1, res.num *= -1;
        res.simple();
        return res;
    }
};

RationalNumber m, n, a, b, c, d;

int main() {
    while(~scanf("%lld/%lld %lld/%lld", &m.num, &m.deno, &n.num, &n.deno)) {
        a = m + n;
        b = m - n;
        c = m * n;
        d = m / n;
        m.simple(), n.simple();

        m.print();
        printf(" + ");
        n.print();
        printf(" = ");
        a.print();
        printf("\n");

        m.print();
        printf(" - ");
        n.print();
        printf(" = ");
        b.print();
        printf("\n");

        m.print();
        printf(" * ");
        n.print();
        printf(" = ");
        c.print();
        printf("\n");

        m.print();
        printf(" / ");
        n.print();
        printf(" = ");
        if(n.integer == 0 && n.num == 0)
            printf("Inf");
        else
            d.print();
        printf("\n");
    }
    return 0;
}