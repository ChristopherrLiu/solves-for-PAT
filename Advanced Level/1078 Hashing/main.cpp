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
#define maxe 300
using namespace std;

int m, n, num, idx[maxn], hashTable[maxn];
bool isNPrime[maxn];

void pre() {
    isNPrime[1] = true;
    for(int i = 2; i < 10010; ++i) {
        if(isNPrime[i])
            continue;
        for(int j = i * i; j > 0 && j < 10010; j += i) {
            isNPrime[j] = true;
        }
    }
}

int main() {
    pre();
    while(~scanf("%d %d", &m, &n)) {
        while(isNPrime[m])
            ++m;
        // cout << m << endl;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &num);
            int cur = num % m;
            if(hashTable[cur]) {
                bool flag = true;
                for(int j = 1; j < m; ++j) {
                    int ncur = (cur + j * j) % m;
                    if(!hashTable[ncur]) {
                        flag = false;
                        idx[i] = ncur;
                        hashTable[ncur] = num;
                        break;
                    }
                }
                if(flag)
                    idx[i] = -1;
            }
            else {
                idx[i] = cur;
                hashTable[cur] = num;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(idx[i] != -1)
                printf("%d%c", idx[i], i == n - 1 ? '\n' : ' ');
            else
                printf("-%c", i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}