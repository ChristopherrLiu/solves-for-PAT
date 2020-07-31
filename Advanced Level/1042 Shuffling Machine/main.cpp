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
#define maxn 55
#define maxe 10010
using namespace std;

char pre[] = {'S', 'H', 'C', 'D', 'J'};
int k, order[maxn], temp[maxn], s[maxn];

int main() {
    while(cin >> k) {
        for(int i = 1; i <= 54; ++i) {
            cin >> s[i];
            order[i] = i;
        }
        for(int i = 1; i <= k; ++i) {
            memcpy(temp, order, sizeof(order));
            for(int j = 1; j <= 54; ++j) {
                order[s[j]] = temp[j];
            }
        }
        for(int i = 1; i <= 54; ++i) {
            printf("%c%d%c", pre[(order[i] - 1) / 13], (order[i] - 1) % 13 + 1, i == 54 ? '\n' : ' ');
        }
    }
    return 0;
}