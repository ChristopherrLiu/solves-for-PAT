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
#define maxe 22
using namespace std;

struct Institution {
    char name[maxe];
    int scoreb, scorea, scoret;
    int tws, ns;
    void calTWS() {
        tws = scoreb * 1.0 / 1.5 + scorea + scoret * 1.5;
    }
    bool operator< (const Institution other) const {
        return tws != other.tws ? tws > other.tws : (
            ns != other.ns ? ns < other.ns : (
                strcmp(name, other.name) != 0 ? strcmp(name, other.name) < 0 : false
            )
        );
    }
};

int n, score, cnt;
char id[maxn], iname[maxn];
map<string, int> name2id, appear;
Institution institutions[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s%d %s", id, &score, iname);
            if(appear[id] == 1)
                continue;
            else
                appear[id] = 1;
            for(int j = 0; j < strlen(iname); ++j) {
                if(iname[j] >= 'A' && iname[j] <= 'Z')
                    iname[j] += 32;
            }
            int idx = name2id[iname];
            if(idx == 0) {
                idx = name2id[iname] = ++cnt;
                strcpy(institutions[idx].name, iname);
            }
            if(id[0] == 'B')
                institutions[idx].scoreb += score;
            else if(id[0] == 'A')
                institutions[idx].scorea += score;
            else
                institutions[idx].scoret += score;
            institutions[idx].ns++;
        }
        for(int i = 1; i<= cnt; ++i)
            institutions[i].calTWS();
        sort(institutions + 1, institutions + cnt + 1);
        printf("%d\n", cnt);
        int rak = 0, num = 1;
        institutions[0].tws = -1;
        for(int i = 1; i <= cnt; ++i) {
            if(institutions[i].tws != institutions[i - 1].tws) {
                rak += num;
                num = 1;
            }
            else {
                ++num;
            }
            printf("%d %s %d %d\n", rak, institutions[i].name, institutions[i].tws, institutions[i].ns);
        }
    }
    return 0;
}