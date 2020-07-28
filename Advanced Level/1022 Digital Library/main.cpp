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
#define maxe 20010
using namespace std;

int n, m;
string id, temp;
map<string, set<string>>title;
map<string, set<string>>author, keywords, publisher, year;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            cin >> id;
            // cout << id << endl;
            getchar();
            getline(cin, temp);
            title[temp].insert(id);
            getline(cin, temp);
            author[temp].insert(id);
            getline(cin, temp);
            int Len = temp.size(), j = 0;
            int k;
            while(j < Len) {
                k = j;
                while(temp[k] != ' ' && k < Len)
                    ++k;
                // cout << temp.substr(j, k - j) << endl;
                keywords[temp.substr(j, k - j)].insert(id);
                j = k + 1;
            }
            getline(cin, temp);
            publisher[temp].insert(id);
            getline(cin, temp);
            year[temp].insert(id);
        }
        scanf("%d", &m);
        getchar();
        for(int i = 0; i < m; ++i) {
            getline(cin, temp);
            string qStr = temp.substr(3, temp.size());
            cout << temp << "\n";
            // cout << temp[0] << endl;
            if(temp[0] == '1') {
                if(title[qStr].size() == 0)
                    puts("Not Found");
                for(auto s : title[qStr]) {
                    cout << s << "\n";
                }
            }
            else if(temp[0] == '2') {
                if(author[qStr].size() == 0)
                    puts("Not Found");
                for(auto s : author[qStr]) {
                    cout << s << "\n";
                }
            }
            else if(temp[0] == '3') {
                if(keywords[qStr].size() == 0)
                    puts("Not Found");
                for(auto s : keywords[qStr]) {
                    cout << s << "\n";
                }
            }
            else if(temp[0] == '4') {
                if(publisher[qStr].size() == 0)
                    puts("Not Found");
                for(auto s : publisher[qStr]) {
                    cout << s << "\n";
                }
            }
            else {
                if(year[qStr].size() == 0)
                    puts("Not Found");
                for(auto s : year[qStr]) {
                    cout << s << "\n";
                }
            }
        }
    }
    return 0;
}