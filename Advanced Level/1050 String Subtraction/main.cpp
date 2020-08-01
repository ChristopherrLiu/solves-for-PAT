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
#define maxe 257
using namespace std;

string s1, s2, ans;
bool vis[maxe];

int main() {
    while(getline(cin, s1)) {
        // getchar();
        getline(cin, s2);
        // cout << s2 << endl;
        for(int i = 0; i < s2.length(); ++i)
            vis[s2[i]] = true;
        for(int i = 0; i < s1.length(); ++i) {
            if(!vis[s1[i]])
                ans += s1[i];
        }
        cout << ans << endl;
    }
    return 0;
}