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
#define maxe 20010
using namespace std;

string n, m;
int k;

string add(string ori) {
    int Len = ori.length(), carry = 0;
    string revOri = ori, res;
    reverse(revOri.begin(), revOri.end());
    for(int i = Len - 1; i >= 0; --i) {
        int curDigit = (ori[i] - '0' + revOri[i] - '0' + carry);
        carry = curDigit / 10;
        curDigit %= 10;
        res += (curDigit + '0');
    }
    if(carry) {
        res += (carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    while(cin >> n >> k) {
        int i;
        m = n;
        reverse(m.begin(), m.end());
        if(n == m) {
            cout << n << "\n";
            cout << 0 << "\n";
            continue;
        }
        for(i = 1; i <= k; ++i) {
            n = add(n);
            m = n;
            reverse(m.begin(), m.end());
            if(n == m) {
                cout << n << "\n";
                cout << i << "\n";
                break;
            }
        }
        if(i > k) {
            cout << n << "\n";
            cout << k << "\n";
        }
    }
}