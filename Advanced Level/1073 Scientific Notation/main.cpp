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
#define maxn 10020
#define maxe 15
using namespace std;

int cnt, scnt, ep;
char sciNota[maxn];
char sign[maxn], pre[maxn];

int main() {
    while(~scanf("%s", sciNota)) {
        int Len = strlen(sciNota);
        if(sciNota[0] == '-')
            pre[cnt++] = '-';
        int i = 1, signNum = 0;
        bool flag = false;
        for(; i < Len && sciNota[i] != 'E'; ++i) {
            if(sciNota[i] == '.') {
                flag = true;
                continue;
            }
            if(flag)
                signNum++;
            sign[scnt++] = sciNota[i];
        }
        sign[scnt] = 0;
        ++i;
        sscanf(sciNota + i, "%d", &ep);
        if(ep < 0) {
            for(int j = 0; j < -ep; ++j) {
                pre[cnt++] = '0';
                if(j == 0)
                    pre[cnt++] = '.';
            }
        }
        else {
            int cur = strlen(sign);
            for(int j = 0; j < ep - signNum; ++j) {
                sign[scnt++] = '0';
            }
            if(ep < signNum) {
                char temp;
                for(int j = cur; j > ep + 1; --j) {
                    sign[j] = sign[j - 1];
                }
                sign[ep + 1] = '.';
            }
        }
        printf("%s%s\n", pre, sign);
    }
    return 0;
}