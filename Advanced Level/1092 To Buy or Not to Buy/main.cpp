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
#define maxn 1010
#define maxe 300
using namespace std;

int nums[maxn], sum;
char beeds[maxn], needBeeds[maxn];

int main() {
    while(~scanf("%s", beeds)) {
        getchar();
        scanf("%s", needBeeds);
        int len = strlen(needBeeds);
        for(int i = 0; i < len; ++i) {
            ++sum;
            nums[needBeeds[i]]++;
        }
        int r = 0, temp = sum;
        len = strlen(beeds);
        for(; r < len; ++r) {
            if(nums[beeds[r]]) {
                --nums[beeds[r]];
                --sum;
                if(sum == 0)
                    break;
            }
        }
        if(sum) {
            printf("No %d\n", sum);
        }
        else {
            printf("Yes %d\n", len - temp);
        }
    }
    return 0;
}