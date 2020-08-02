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
#define maxe 10
using namespace std;

struct Person {
    char name[10];
    int age, wealth;
    bool operator< (const Person other) const {
        return wealth != other.wealth ? wealth > other.wealth : (age != other.age ? age < other.age : strcmp(name, other.name) != 0 ?
            strcmp(name, other.name) < 0 : false);
    }
};

int n, k, m, amin, amax;
Person persons[maxn];

int main() {
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s %d %d", persons[i].name, &persons[i].age, &persons[i].wealth);
        }
        sort(persons, persons + n);
        for(int i = 0; i < k; ++i) {
            scanf("%d %d %d", &m, &amin, &amax);
            int cnt = 0;
            printf("Case #%d:\n", i + 1);
            for(int j = 0;  j < n; ++j) {
                if(cnt >= m) {
                    break;
                }
                if(persons[j].age >= amin && persons[j].age <= amax) {
                    cnt++;  
                    printf("%s %d %d\n", persons[j].name, persons[j].age, persons[j].wealth);
                }
            }
            if(cnt == 0) {
                puts("None");
            }
        }
    }
    return 0;
}