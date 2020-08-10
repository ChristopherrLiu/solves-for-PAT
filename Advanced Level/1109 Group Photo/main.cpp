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
#define maxe 12
using namespace std;

int n, k, nums[maxe];
char mapp[maxe][maxn / maxe * 10][maxe];

struct Person {
    char name[maxe];
    int height;
    bool operator< (const Person other) const {
        return height != other.height ? height < other.height : (
            strcmp(name, other.name) != 0 ? strcmp(name, other.name) > 0 : false
        );
    }
}persons[maxn];

int main() {
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s%d", persons[i].name, &persons[i].height);
        }
        sort(persons, persons + n);
        int rowNumber = floor(n * 1.0 / k);
        int l = 0, r;
        for(int i = 1; i <= k; ++i) {
            if(i == k)
                rowNumber = n - rowNumber * (k - 1);
            r = l + rowNumber - 1;
            int mid = floor(rowNumber * 1.0 / 2), ll = mid - 1, rr = mid + 1;
            strcpy(mapp[i][mid], persons[r].name);
            for(int j = r - 1, p = 1; j >= l; --j, ++p) {
                if(p % 2) {
                    if(ll == -1) {
                        ++j;
                        continue;
                    }
                    strcpy(mapp[i][ll--], persons[j].name);
                }
                else {
                    if(rr == rowNumber) {
                        ++j;
                        continue;
                    }
                    strcpy(mapp[i][rr++], persons[j].name);
                }
            }
            nums[i] = rowNumber;
            l = r + 1;
        }
        for(int i = k; i >= 1; --i) {
            for(int j = 0; j < nums[i]; ++j) {
                printf("%s%c", mapp[i][j], j == nums[i] - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}