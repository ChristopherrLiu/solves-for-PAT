#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 110
#define maxe 130
#define maxk 65
using namespace std;

int n;
int origin[maxn], partSort[maxn], temp[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &origin[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &partSort[i]);
        }
        int flag = 0, pt = 1;
        while(pt < n && partSort[pt] >= partSort[pt - 1])
            ++pt;
        for(int i = pt; i < n; ++i) {
            if(partSort[i] != origin[i]) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            printf("Merge Sort\n");
            memcpy(temp, partSort, sizeof(partSort));
            int cnt = 0;
            for(int i = 0; i < n; i += 2 * pt) {
                int pt1 = i, pt2 = i + pt;
                while(pt1 < min(i + pt, n) && pt2 < min(i + 2 * pt, n)) {
                    if(temp[pt1] <= temp[pt2]) 
                        partSort[cnt++] = temp[pt1++];
                    else 
                        partSort[cnt++] = temp[pt2++];
                }
                while(pt1 < min(i + pt, n))
                    partSort[cnt++] = temp[pt1++];
                while(pt2 < min(i + 2 * pt, n))
                    partSort[cnt++] = temp[pt2++];
            }
        }
        else {
            printf("Insertion Sort\n");
            int i = 0, tag = partSort[pt];
            for(; i < pt; ++i) {
                if(partSort[i] > tag)
                    break;
            }
            for(int j = pt; j > i; --j) {
                partSort[j] = partSort[j - 1];
            }
            partSort[i] = tag;
        }
        for(int i = 0; i < n; ++i)
            printf("%d%c", partSort[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}