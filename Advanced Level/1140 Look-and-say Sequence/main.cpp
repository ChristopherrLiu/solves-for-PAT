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
#define maxe 22
using namespace std;

int n;
string seq;

int main() {
    while(cin >> seq >> n) {
        for(int i = 0; i < n - 1; ++i) {
            string temp = seq;
            seq.clear();
            for(int j = 0; j < temp.length(); ++j) {
                int k = j;
                while(k < temp.length() && temp[k] == temp[j])
                    ++k;
                seq += temp[j];
                seq += (k - j) + '0';
                j = k - 1;
            }
        }
        cout << seq << endl;
    }
    return 0;
}