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
#define maxn 50010
#define maxe 22
using namespace std;

struct Student {
    char id[maxe];
    int pgrade, mgrade, fgrade, ffgrade;
    void init() {
        pgrade = mgrade = fgrade = -1;
        ffgrade = -1;
    }
    void calFinalGrade() {
        ffgrade = fgrade;
        if(mgrade > fgrade) {
            int m = mgrade < 0 ? 0 : mgrade;
            int f = fgrade < 0 ? 0 : fgrade;

            ffgrade = m * 0.4 + f * 0.6 + 0.5;
        }
    }
    bool operator< (const Student other) const {
        return ffgrade != other.ffgrade ? ffgrade > other.ffgrade : (
            strcmp(id, other.id) != 0 ? strcmp(id, other.id) < 0 : false
        );
    }
};

int p, m, n, cnt;
char id[maxe];
Student students[maxn];
map<string, int>id2id;
vector<Student> ranklist;

int main() {
    while(~scanf("%d %d %d", &p, &m, &n)) {
        for(int i = 0; i < p; ++i) {
            getchar();
            scanf("%s", id);
            int idx = id2id[id];
            if(idx == 0) {
                idx = id2id[id] = ++cnt;
                strcpy(students[idx].id, id);
                students[idx].init();
            }
            scanf("%d", &students[idx].pgrade);
        }
        for(int i = 0; i < m; ++i) {
            getchar();
            scanf("%s", id);
            int idx = id2id[id];
            if(idx == 0) {
                idx = id2id[id] = ++cnt;
                strcpy(students[idx].id, id);
                students[idx].init();
            }
            scanf("%d", &students[idx].mgrade);
        }
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s", id);
            int idx = id2id[id];
            if(idx == 0) {
                idx = id2id[id] = ++cnt;
                strcpy(students[idx].id, id);
                students[idx].init();
            }
            scanf("%d", &students[idx].fgrade);
        }
        for(int i = 1; i <= cnt; ++i) {
            students[i].calFinalGrade();
            if(students[i].pgrade >= 200 && students[i].ffgrade >= 60)
                ranklist.push_back(students[i]);
        }
        sort(ranklist.begin(), ranklist.end());
        for(auto student : ranklist) {
            printf("%s %d %d %d %d\n", student.id, student.pgrade, student.mgrade, student.fgrade, student.ffgrade);
        }
    }
    return 0;
}