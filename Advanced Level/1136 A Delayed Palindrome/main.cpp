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
#define maxe 22
using namespace std;

string num, rev, temp;

int main() {
    while(cin >> num) {
        int cnt = 0;
        rev = num;
        reverse(rev.begin(), rev.end());
        while(rev != num && cnt < 10) {
            temp = num;
            num.clear();
            printf("%s + %s = ", temp.c_str(), rev.c_str());
            int len = temp.length(), ca = 0, cur;
            for(int i = len - 1; i >= 0; --i) {
                cur = (temp[i] - '0') + (rev[i] - '0') + ca;
                ca = cur / 10;
                cur %= 10;
                num += cur + '0';
            }
            if(ca)
                num += ca + '0';
            rev = num;
            reverse(num.begin(), num.end());
            printf("%s\n", num.c_str());
            ++cnt;
        }
        if(cnt >= 10 && rev != num)
            printf("Not found in 10 iterations.\n");
        else
            printf("%s is a palindromic number.\n", num.c_str());
    }
    return 0;
}