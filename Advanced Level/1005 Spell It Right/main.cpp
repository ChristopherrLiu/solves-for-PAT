#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;

char num[maxn], res[maxn];
char num2str[][10] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", ""
};
int base[] = {1000, 100, 10, 1};

int main() {
    while(cin >> num) {
        int Len = strlen(num);
        int sum = 0, flag = 0;
        for(int i = 0; i < Len; ++i) {
            sum += num[i] - '0';
        }
        if(sum == 0) {
            printf("%s\n", "zero");
            continue;
        }
        sprintf(res, "%d", sum);
        Len = strlen(res);
        for(int i = 0; i < Len; ++i) {
            if(flag)
                printf(" %s", num2str[res[i] - '0']);
            else
                printf("%s", num2str[res[i] - '0']);
            flag = 1;
        }
        printf("\n");
    }
    return 0;
}