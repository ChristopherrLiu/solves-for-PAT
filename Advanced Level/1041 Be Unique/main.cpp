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
#define maxe 10010
using namespace std;

int n, nums[maxn];
int freq[maxe];

int main() {
    while(cin >> n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
            freq[nums[i]]++;
        }
        bool flag = false;
        for(int i = 0; i < n; ++i) {
            if(freq[nums[i]] == 1) {
                flag = true;
                printf("%d\n", nums[i]);
                break;
            }
        }
        if(!flag)
            puts("None");    
    }
    return 0;
}