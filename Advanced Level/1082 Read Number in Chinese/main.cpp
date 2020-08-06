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
#define maxn 110
#define maxe 110
#define maxk 6
using namespace std;

char digitsName[][10] = {
    "", "Shi ", "Bai ", "Qian ", "Wan ", "Shi ", "Bai ", "Qian ", "Yi ", "Shi Yi ", "Bai Yi "
};

char numName[][10] = {
    "ling ", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

char inputs[maxn];

int cnt;
char ans[maxn][maxn];

int main() {
    while(~scanf("%s", &inputs)) {
        int len = strlen(inputs), n = abs(atoi(inputs));
        int i = len - 1, digitNum = 0;
        while(inputs[i] == '0')
            --i, digitNum++;
        for(; i >= 0; --i) {
            if(i == 0 && inputs[i] == '-') {
                strcpy(ans[cnt], "Fu ");
                cnt++;
                continue;
            }
            if(inputs[i] == '0') {
                if(digitNum == 4) {
                    n /= 10000;
                    if(n % 10000) {
                        strcpy(ans[cnt], digitsName[digitNum]);
                        cnt++;
                    }
                }
                if(strcmp(ans[cnt - 1], "Wan ") == 0 || strcmp(ans[cnt - 1], "ling ") == 0) {
                    digitNum++;
                    continue;
                }
                strcpy(ans[cnt], numName[0]);
                cnt++, digitNum++;
                continue;
            }
            strcpy(ans[cnt], numName[inputs[i] - '0']);
            if(digitNum > 0) {
                int curLen = strlen(ans[cnt]);
                ans[cnt][curLen] = ' ';
                strcpy(ans[cnt] + curLen + 1, digitsName[digitNum]);
            }
            cnt++; digitNum++;
        }
        if(strcmp(inputs, "0") == 0) {
            printf("ling\n");
            continue;
        }
        int pt = strlen(ans[0])  - 1;
        while(ans[0][pt] == ' ')
            --pt;
        ans[0][pt + 1] = 0;
        for(int i = cnt - 1; i >= 0; --i) {
            printf("%s", ans[i]);
        }
        printf("\n");
    }
    return 0;
}