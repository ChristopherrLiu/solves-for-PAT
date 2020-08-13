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

int n, preOrder[maxn], inOrder[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &preOrder[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &inOrder[i]);
        int il = 0, ir = n - 1, pl = 0, pr = n - 1;
        while(pl < pr) {
            int temp = preOrder[pl];
            int mid = il;
            while(inOrder[mid] != temp)
                ++mid;
            if(mid == il) {
                il = mid + 1;
                pl = pl + 1;
            }
            else {
                ir = mid - 1;
                pr = pl + mid - il;
                pl = pl + 1;
            }
        }
        printf("%d\n", preOrder[pl]);
    }
    return 0;
}