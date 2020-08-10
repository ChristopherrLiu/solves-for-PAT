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
#define maxe 10
using namespace std;


int n;
string str;

char marsDigit[2][13][10] = {
    {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
    {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
};

int main() {
    while(~scanf("%d", &n)) {
        getchar();
        for(int j = 0; j < n; ++j) {
            int cnt = 0;
            getline(cin, str);
            if(str[0] >= '0' && str[0] <= '9') {
                int num = stoi(str);
                if(num / 13)
                    printf("%s", marsDigit[1][num / 13]);
                if(num / 13 && num % 13)
                    printf(" ");
                if(num % 13 || num == 0)
                    printf("%s", marsDigit[0][num % 13]);
                printf("\n");
            }
            else {
                string s1 = "", s2 = "";
                int len = str.length();
                s2 = str.substr(0, 3);
                if(len > 4) {
                    s1 = str.substr(4, 3);
                }
                int num1 = 0, num2 = 0;
                for(int i = 1; i <= 12; ++i) {
                    if(s1 == marsDigit[0][i] || s2 == marsDigit[0][i])
                        num2 = i;
                    if(s2 == marsDigit[1][i])
                        num1 = i;
                }
                printf("%d\n", num1 * 13 + num2);
            }
        }
    }
    return 0;
}