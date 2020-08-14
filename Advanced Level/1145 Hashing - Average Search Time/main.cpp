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
#define maxn 10020
#define maxe 22
using namespace std;

int msize, n, m, key, hashTable[maxn];
bool nprime[maxn];

void pre() {
    nprime[1] = true;
    for(int i = 2; i <= 10010; ++i) {
        if(nprime[i])
            continue;
        for(int j = i * i; j <= 10010; j += i) {
            nprime[j] = true;
        }
    }
}

bool insert() {
    int pos = key % msize;
    if(hashTable[pos]) {
        for(int i = 1; i <= msize; ++i) {
            if(!hashTable[(pos + i * i) % msize]) {
                hashTable[(pos + i * i) % msize] = key;
                return true;
            }
        }
        return false;
    }
    else {
        hashTable[pos] = key;
        return true;
    }
}

int search() {
    int num = 1, pos = key % msize;
    if(hashTable[pos] == key) {
        return num;
    }
    else {
        if(hashTable[pos] == 0)
            return num;
        for(int i = 1; i <= msize; ++i) {
             ++num;
            if(hashTable[(pos + i * i) % msize] == key || hashTable[(pos + i * i) % msize] == 0) {
                return num;
            }

        }
        return num;
    }
}

int main() {
    pre();
    while(~scanf("%d %d %d", &msize, &n, &m)) {
        while(nprime[msize])
            msize++;
        for(int i = 0 ; i < n; ++i) {
            scanf("%d", &key);
            if(!insert())
                printf("%d cannot be inserted.\n", key);
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &key);
            ans += search();
        }
        printf("%.1f\n", ans * 1.0 / m);
    }
    return 0;
}