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

int digits[10];
string n, m;

int main() {
    while(cin >> n) {
        int Len = n.length();
        int carry = 0;
        for(int i = Len - 1; i >= 0; --i) {
            int currentdigit = (n[i] - '0') * 2 + carry;
            carry = currentdigit / 10;
            currentdigit %= 10;
            m += (currentdigit + '0');
        }
        // cout << n << endl;
        // cout << m << endl;
        if(carry) {
            m += (carry + '0');
            reverse(m.begin(), m.end());
            puts("No");
            cout << m << "\n";
        }
        else {
            reverse(m.begin(), m.end());
            for(int i = Len - 1; i >= 0; --i)
                digits[n[i] - '0']++;
            for(int i = Len - 1; i >= 0; --i)
                digits[m[i] - '0']--;
            bool flag = false;
            for(int i = 0; i < 10; ++i) {
                if(digits[i]) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                puts("No");
                cout << m << "\n";
            }
            else {
                puts("Yes");
                cout << m << "\n";
            }
        }
    }
    return 0;
}