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
long long c, a, b;
char nums[maxn], temp[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s", nums);
            c = atoi(nums);
            int len = strlen(nums);
            strncpy(temp, nums, len / 2);
            temp[len / 2] = 0;
            a = atoi(temp);
            strncpy(temp, nums + len / 2, len / 2);
            temp[len / 2] = 0;
            b = atoi(temp);
            if(a * b == 0)
                puts("No");
            else if(c % (a * b) == 0)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}