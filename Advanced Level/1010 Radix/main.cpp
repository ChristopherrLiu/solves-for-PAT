#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;

int tag;
ll radix, num1, num2;
string n1, n2;

ll decode(char n) {
    if(n >= '0' && n <= '9')
        return n - '0';
    else
        return n - 'a' + 10;
}

int check(ll num1, ll b) {
    ll base = 1;
    num2 = 0;
    int Len = n2.length();
    for(int i = Len - 1; i >= 0; --i) {
        num2 = num2 + (decode(n2[i]) * base);
        base = base * b;
        // if(b == 2)
        //     cout << base << endl;
        if(base < 0 || num2 < 0 || num2 > num1)
            return 1;
    }
    if(num2 == num1)
        return 0;
    else
        return -1;
}

int main() {
    while(cin >> n1 >> n2 >> tag >> radix) {
        if(tag == 2)
            swap(n1, n2);
        int Len = n1.length();
        ll base = 1;
        for(int i = Len - 1; i >= 0; --i) {
            num1 = num1 + (decode(n1[i]) * base);
            base = base * radix;
        }
        bool tag = false;
        Len = n2.length();
        ll left = 2, right = num1 + 1;
        for(int i = n2.size() - 1; i >= 0; --i) {
            if(decode(n2[i]) >= left)
                left = decode(n2[i]) + 1;
        }
        if(n2.size() == 1) {
            if(decode(n2[0]) == num1)
                printf("%lld\n", left);
            else
                printf("Impossible\n");
            continue;
        }
        while(left <= right) {
            ll mid = (left + right) >> 1;;
            int flag = check(num1, mid);
            if(flag == 1) {
                right = mid - 1;
            }
            else if(flag == 0) {
                tag = true;
                printf("%lld\n", mid);
                break;
            }
            else {
                left = mid + 1;
            }
        }
        if(!tag)
            printf("Impossible\n");
    }
    return 0;
}