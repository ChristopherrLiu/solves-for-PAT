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
#define maxn 100010
#define maxe 10
using namespace std;

int n;
int origin[maxn], partSort[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &origin[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &partSort[i]);
        bool flag = false;
        int pt = 1;
        while(partSort[pt] >= partSort[pt - 1])
            ++pt;
        for(int i = pt; i < n; ++i)
            if(partSort[i] != origin[i]) {
                flag = true;
                break;
            }
        if(flag) {
            puts("Heap Sort");
            sort(origin, origin + n);
            int pt = n - 1;
            while(pt >= 0 && partSort[pt] == origin[pt])
                --pt;
            
            int curMax = partSort[0], i = 1;
            while(2 * i + 1 <= pt + 1) {
                int cur = i * 2;
                if(partSort[i * 2] > partSort[i * 2 - 1])
                    cur = i * 2 + 1;
                swap(partSort[i - 1], partSort[cur - 1]);
                i = cur;
            }
            swap(partSort[i - 1], partSort[pt]);
        }
        else {
            puts("Insertion Sort");
            sort(partSort, partSort + pt + 1);
        }
        for(int i = 0; i < n; ++i)
            printf("%d%c", partSort[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}