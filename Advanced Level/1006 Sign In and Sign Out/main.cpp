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
const int maxn = 21;

struct Time {
    int h, m, s;
    bool operator< (const Time other) const {
        if(this->h < other.h)
            return true;
        else if(this->m < other.m)
            return true;
        else if(this->s < other.s)
            return true;
        return false;
    }
    bool operator> (const Time other) const {
        if(this->h > other.h)
            return true;
        else if(this->m > other.m)
            return true;
        else if(this->s > other.s)
            return true;
        return false;
    }
}signIn, signOut, minTag, maxTag;

int n;
char unlocked[maxn], locked[maxn], ids[maxn];

int main() {
    minTag.h = 0, minTag.m = 0, minTag.s = 0;
    maxTag.h = 23, maxTag.m = 59, maxTag.s = 59;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s %d:%d:%d %d:%d:%d", ids, &signIn.h, &signIn.m, &signIn.s, &signOut.h, &signOut.m, &signOut.s);
            if(signIn < maxTag) {
                maxTag = signIn;
                sprintf(unlocked, "%s", ids);
            }
            if(signOut > minTag) {
                minTag = signOut;
                sprintf(locked, "%s", ids);
            }
        }
        printf("%s %s\n", unlocked, locked);
    }
    return 0;
}