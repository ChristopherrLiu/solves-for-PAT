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
#define maxe 250010
using namespace std;

struct Node {
    char c;
    int back;
    bool flag;
    vector<int> pre;
};

int id, n, s1, s2, tailNum, tail;
Node nodes[maxn];

int main() {
    while(~scanf("%d %d %d", &s1, &s2, &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &id);
            getchar();
            scanf("%c %d", &nodes[id].c, &nodes[id].back);
            // cout << nodes[id].c << endl;
            if(nodes[id].back == -1)
                tailNum++, tail = id;
            else
                nodes[nodes[id].back].pre .push_back(id);
        }
        // getchar();
        // getchar();
        int ans;
        for(int i = s1; i != -1; i = nodes[i].back)
            nodes[i].flag = true;
        for(ans = s2; ans != -1; ans = nodes[ans].back)
            if(nodes[ans].flag)
                break;
        if(ans == -1) {
            puts("-1");
        }
        else {
            printf("%05d\n", ans);
        }
    }
    return 0;
}