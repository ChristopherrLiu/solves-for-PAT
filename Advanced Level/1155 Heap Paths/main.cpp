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
#define maxe 1010
#define DEBUG
using namespace std;

int n, lastretion, keys[maxn];
vector<int> path;
bool flag;

void dfs(int id, int pre) {
    if(id > n) {
        return;
    }
    if(id > 1) {
        if(lastretion == -1) {
            if(keys[id] > pre)
                lastretion = 1;
            else if(keys[id] < pre)
                lastretion = 0;
        }
        else {  
            if(lastretion == 0 && keys[id] > pre) {
                flag = false;
            }
            else if(lastretion == 1 && keys[id] < pre) {
                flag = false;
            }
        }
    }
    path.push_back(keys[id]);
    if(id * 2 > n)
        for(int i = 0; i < path.size(); ++i) {
            printf("%d%c", path[i], i == path.size() - 1 ? '\n' : ' ');
        }
    dfs(id * 2 + 1, keys[id]);
    dfs(id * 2, keys[id]);
    path.pop_back();
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) 
        cin >> keys[i];
    
    lastretion = -1;
    flag = true;
    dfs(1, -1);
    if(flag) {
        if(lastretion == 0)
            puts("Max Heap");
        else
            puts("Min Heap");
    }
    else {
        puts("Not Heap");
    }

    #ifdef DEBUG
        getchar();
        getchar();
    #endif
    return 0;
}