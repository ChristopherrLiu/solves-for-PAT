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
#define maxe 250010
using namespace std;

struct Acount {
    string name, password;
};

int n;
Acount acounts[maxn];
vector<Acount> ans;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            cin >> acounts[i].name >> acounts[i].password;
        }
        for(int i = 0; i < n; ++i) {
            int Len = acounts[i].password.length();
            bool flag = false;
            for(int j = 0; j < Len; ++j) {
                if(acounts[i].password[j] == '1')
                    flag = true, acounts[i].password[j] = '@';
                else if(acounts[i].password[j] == '0')
                    flag = true, acounts[i].password[j] = '%';
                else if(acounts[i].password[j] == 'l')
                    flag = true, acounts[i].password[j] = 'L';
                else if(acounts[i].password[j] == 'O')
                    flag = true, acounts[i].password[j] = 'o';
            }
            if(flag)
                ans.push_back(acounts[i]);
        }
        if(ans.size() == 0) {
            if(n == 1)
                printf("There is %d account and no account is modified\n", n);
            else
                printf("There are %d accounts and no account is modified\n", n);
        }
        else {
            printf("%d\n", ans.size());
            for(auto a : ans) {
                cout << a.name << " " << a.password << "\n";
            }
        }
    }
    return 0;
}