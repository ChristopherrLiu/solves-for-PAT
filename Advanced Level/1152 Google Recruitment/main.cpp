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
#define maxe 2100
#define DEBUG
using namespace std;

int l, k;
long long subnum;
string strnum;

int main() {
    cin >> l >> k;
    cin >> strnum;
    int len = strnum.length();
    bool find = false, prime = true;
    for(int i = 0; i <= len - k; ++i) {
        subnum = (long long)stoi(strnum.substr(i, k));
        long long mid = sqrt(subnum * 1.0);
        prime = true;
        for(long long fac = 2; fac <= mid; ++fac) {
            if(subnum % fac == 0) {
                prime = false;
                break;
            }
        }
        if(prime) {
            cout << strnum.substr(i, k) << endl;
            find = true;
            break;
        }
    }
    if(!find)
        cout << "404" << endl;
    #ifdef DEBUG
        getchar();
        getchar();
    #endif
    return 0;
}