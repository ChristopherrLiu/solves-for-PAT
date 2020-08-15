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
#define maxe 22
using namespace std;

int n, m, seqs[maxn], lastRetion;
bool flag;

void dfs(int id, int pre) {
    if(id > m)
        return;
    if(!flag)
        return;
    if(id > 1 && lastRetion == -1) {
        if(seqs[id] <= pre)
            lastRetion = 0;
        else if(seqs[id] >= pre)
            lastRetion = 1;
    }
    else if(id > 1) {
        if(lastRetion == 0 && seqs[id] > pre)
            flag = false;
        if(lastRetion == 1 && seqs[id] < pre)
            flag = false;
    }
    dfs(id * 2, seqs[id]);
    dfs(id * 2 + 1, seqs[id]);
}

void postOrder(int id) {
    if(id > m)
        return;
    postOrder(id * 2);
    postOrder(id * 2 + 1);
    printf("%d%c", seqs[id], id == 1 ? '\n' : ' ');
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &seqs[j]);
            }
            flag = true;
            lastRetion = -1;
            dfs(1, -1);
            if(flag)
                if(lastRetion)
                    puts("Min Heap");
                else
                    puts("Max Heap");
            else
                puts("Not Heap");
            postOrder(1);
        }
    }
    return 0;
}