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
#define maxe 10
using namespace std;

int n, len, fid;
char nums[maxe];
set<int> lists;

int main() {
    while(~scanf("%d", &n)) {
        getchar();
        for(int i = 0; i < n; ++i) {
            scanf("%s", nums);
            len = strlen(nums);
            fid = 0;
            for(int j = 0; j < len; ++j)
                fid += nums[j] - '0';
            lists.insert(fid);
        }
        int cnt = lists.size();
        printf("%d\n", cnt);
        for(auto id : lists)
            printf("%d%c", id, cnt-- == 1 ? '\n' : ' ');
    }
    return 0;
}