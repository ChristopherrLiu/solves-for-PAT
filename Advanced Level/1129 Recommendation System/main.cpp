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
#define maxn 50010
#define maxe 22
using namespace std;

int n, k, cnt, items[maxn], appearn[maxn], recommend[maxe];

bool cmp(int idx1, int idx2) {
    if(appearn[idx1] > appearn[idx2])
        return true;
    if(appearn[idx1] == appearn[idx2] && idx1 < idx2)
        return true;
    return false;
}

void update(int key) {
    int inIdx;
    bool in = false;
    for(int i = 0; i < cnt; ++i) {
        if(recommend[i] == key) {
            in = true;
            inIdx = i;
            break;
        }
    }
    if(in) {
        while(inIdx > 0 && cmp(recommend[inIdx], recommend[inIdx - 1])) {
            swap(recommend[inIdx], recommend[inIdx - 1]);
            inIdx = inIdx - 1;
        }
    }
    else {
        if(cnt < k) {
            recommend[cnt++] = key;
            inIdx = cnt - 1;
            while(inIdx > 0 && cmp(recommend[inIdx], recommend[inIdx - 1])) {
                swap(recommend[inIdx], recommend[inIdx - 1]);
                inIdx = inIdx - 1;
            }
        }
        else {
            if(cmp(key, recommend[cnt - 1])) {
                recommend[cnt - 1] = key;
                inIdx = cnt - 1;
                while(inIdx > 0 && cmp(recommend[inIdx], recommend[inIdx - 1])) {
                    swap(recommend[inIdx], recommend[inIdx - 1]);
                    inIdx = inIdx - 1;
                }
            }
        }
    }
}

int main() {
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &items[i]);
        }
        for(int i = 0; i < n; ++i) {
            if(i > 0) {
                printf("%d:", items[i]);
                for(int j = 0; j < min(cnt, k); ++j)
                    printf(" %d", recommend[j]);
                printf("\n");
            }
            appearn[items[i]]++;
            update(items[i]);
        }
    }
    return 0;
}