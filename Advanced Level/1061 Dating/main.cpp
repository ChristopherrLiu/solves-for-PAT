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
#define maxn 110
#define maxe 10
using namespace std;

string s1, s2, s3, s4;

char weekDay[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    while(getline(cin, s1)) {
        getline(cin, s2);
        getline(cin, s3);
        getline(cin, s4);
        // printf("%d %d", 'a', 'A');
        int d, h, m, tagd;
        bool flag = false;
        int Len = s1.length();
        for(int i = 0; i < Len; ++i) {
            if(!flag && s1[i] >= 'A' && s1[i] <= 'G' && s2[i] == s1[i]) {
                d = s1[i] - 'A';
                tagd = i;
                flag = true;
                continue;
            }
            if(flag && s1[i] >= 'A' && s1[i] <= 'N') {
                if(s2[i] == s1[i]) {
                    h = s1[i] - 'A' + 10;
                    break;
                }
            }
            if(flag && s1[i] >= '0' && s1[i] <= '9') {
                if(s2[i] == s1[i]) {
                    h = s1[i] - '0';
                    break;
                }
            }
        }
        Len = s3.length();
        for(int i = 0; i < Len; ++i) {
            if(s3[i] >= 'a' && s3[i] <= 'z') {
                if(s4[i] == s3[i]) {
                    m = i;
                    break;
                }
            }
            else if(s3[i] >= 'A' && s3[i] <= 'Z') {
                if(s4[i] == s3[i]) {
                    m = i;
                    break;
                }
            }
        }
        // cout << d<< endl;
        printf("%s %02d:%02d\n", weekDay[d], h, m);
    }
    return 0;
}