#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
bool flag;
stringstream ss;
string str;
vector<string> ans;

int main() {
    while(~scanf("%d %d", &a, &b)) {
        int c = a + b, temp;
        ans.clear();
        flag = false;
        if(c < 0) {
            flag = true;
            c *= -1;
        }
        ss.clear();
        ss << c;
        ss >> str;
        if(flag)
            printf("-");
        int Len = str.length();
        reverse(str.begin(), str.end());
        for(int i = 0; i < Len; i += 3) {
            string temp = str.substr(i, 3);
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        int cnt = 0;
        for(auto s : ans) {
            if(cnt > 0)
                printf(",");
            cout << s;
            cnt++;
        }
        printf("\n");
    }
    return 0;
}