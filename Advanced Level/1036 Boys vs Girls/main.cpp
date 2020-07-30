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

struct Student {
    string name, gender, id;
    int grade;
};

int n;
int tag1, tag2;
bool flag1, flag2;
Student input, minMale, maxFemale;

int main() {
    tag1 = 100, tag2 = 0;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            cin >> input.name >> input.gender >> input.id >> input.grade;
            if(input.gender == "M") {
                flag1 = true;
                if(input.grade < tag1) {
                    tag1 = input.grade;
                    minMale = input;
                }
            }
            else {
                flag2 = true;
                if(input.grade > tag2) {
                    tag2 = input.grade;
                    maxFemale = input;
                }
            }
        }
        if(!flag2) {
            puts("Absent");
        }
        else {
            cout << maxFemale.name << " " << maxFemale.id << "\n";
        }
        if(!flag1) {
            puts("Absent");
        }
        else {
            cout << minMale.name << " " << minMale.id << "\n";
        }
        if(!flag1 || !flag2) {
            puts("NA");
        }
        else {
            printf("%d\n", maxFemale.grade - minMale.grade);
        }
    }
    return 0;
}