#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 100010
#define maxe 1000010
using namespace std;

int n, d;
string num;
bool isPrime[maxn];

void pre() {
    isPrime[0] = isPrime[1] = true;
    for(int i = 2; i <= 100000; ++i) {
        if(!isPrime[i]) {
            for(int j = i * i; j > 0 && j <= 100000; j += i) {
                if(j < 0)
                    continue;
                isPrime[j] = true;
            }
        }
    }
}

int main() {
    pre();
    while(~scanf("%d %d", &n, &d) && n > 0) {
        int temp = n, base = d;
        num.clear();
        while(temp) {
            num += (temp % base) + '0';
            temp /= base;
            // base *= d;
        }
        int Len = num.length();
        base = 1;
        // cout << num[0] << endl;
        for(int i = Len - 1; i >= 0; --i) {
            temp += (num[i] - '0') * base;
            base *= d;
        }
        // cout << temp << endl;
        if(!isPrime[temp] && !isPrime[n])
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}