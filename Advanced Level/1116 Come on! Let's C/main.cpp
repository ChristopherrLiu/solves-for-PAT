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
#define maxe 2
using namespace std;

int n, k, id;
int ranks[maxn];
bool nPrime[maxn], inRank[maxn], queried[maxn];

void pre() {
    for(int i = 2; i <= 10000; ++i) {
        if(nPrime[i])
            continue;
        for(int j = i * i; j <= 10000; j += i)
            nPrime[j] = true;
    }
}

int main() {
    pre();
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &id);
            ranks[id] = i + 1;
            inRank[id] = true;
        }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d", &id);
            printf("%04d: ", id);
            if(!inRank[id]) {
                // queried[id] = true;
                printf("Are you kidding?\n");
            }
            else if(queried[id]) {
                printf("Checked\n");
            }
            else {
                queried[id] = true;
                if(ranks[id] == 1) {
                    printf("Mystery Award\n");
                }
                else if (!nPrime[ranks[id]]){
                    printf("Minion\n");
                }
                else {
                    printf("Chocolate\n");
                }
            }
        }
    }
    return 0;
}