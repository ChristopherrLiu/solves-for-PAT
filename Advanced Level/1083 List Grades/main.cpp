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
#define maxe 15
#define maxk 6
using namespace std;

struct Person {
    char name[maxe], id[maxe];
    int grade;

    bool operator< (const Person other) const {
        return grade > other.grade;
    }
};

int n, lg, rg;
Person persons[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%s%s%d", persons[i].name, persons[i].id, &persons[i].grade);
        }
        scanf("%d %d", &lg, &rg);
        sort(persons, persons + n);
        bool flag = false;
        for(int i = 0; i < n; ++i) {
            if(persons[i].grade < lg || persons[i].grade > rg)
                continue;
            flag = true;
            printf("%s %s\n", persons[i].name, persons[i].id);
        }
        if(!flag) 
            puts("NONE");
    }
    return 0;
}