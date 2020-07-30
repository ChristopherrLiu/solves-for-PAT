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
#define maxn 500010
#define maxe 250010
using namespace std;

int n, k, cid, nk, cnt;
char names[20];
string name;
map<string, int> name2id;
set<int> courses[maxn];

int main() {
    while(cin >> n >> k) {
        for(int i = 0; i < k; ++i) {
            cin >> cid >> nk;
            for(int i = 0; i < nk; ++i) {
                getchar();
                scanf("%s", names);
                name = names;
                if(name2id[name] == 0)
                    name2id[name] = ++cnt;
                courses[name2id[name]].insert(cid);
            }
        }
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s", names);
            name = names;
            cout << name << " ";
            if(name2id[name] == 0) {
                cout << 0 << "\n";
                continue;
            }
            cout << courses[name2id[name]].size();
            for(auto c : courses[name2id[name]]) {
                cout << " " << c; 
            }
            cout << "\n";
        }
    }
    return 0;
}