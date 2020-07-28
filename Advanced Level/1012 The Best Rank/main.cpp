#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 2010;

struct Grade {
    int grade, id;
    bool operator< (const Grade other) const {
        return this->grade > other.grade;
    }
    bool operator== (const Grade other) const {
        return this->grade == other.grade;
    }
};

int n, q, bestRank[maxn], bestCourse[maxn];
char courses[] = {'C', 'M', 'E', 'A'};
Grade c[maxn], m[maxn], e[maxn], a[maxn];
string name;
map<string, int> name2id;

void solve(Grade *gs, int cId) {
    sort(gs + 1, gs + n + 1);
    int rank = 1;
    for(int i = 1; i <= n; ++i) {
        if(i > 1 && gs[i].grade != gs[i - 1].grade)
            rank = i;
        if(rank < bestRank[gs[i].id]) {
            bestRank[gs[i].id] = rank;
            bestCourse[gs[i].id] = cId;
        }
        else if(rank == bestRank[gs[i].id]) {
            bestCourse[gs[i].id] = cId;
        }
    }
}

int main() {
    while(cin >> n >> q) {
        memset(bestRank, 0x3f, sizeof(bestRank));
        for(int i = 1; i <= n; ++i) {
            cin >> name >> c[i].grade >> m[i].grade >> e[i].grade;
            a[i].grade = (c[i].grade + m[i].grade + e[i].grade) / 3;
            c[i].id = m[i].id = e[i].id = a[i].id = i;
            name2id[name] = i;
        }
        solve(e, 2), solve(m, 1), solve(c, 0), solve(a, 3);
        for(int i = 1; i <= q; ++i) {
            cin >> name;
            if(name2id[name] == 0)
                cout << "N/A\n";
            else
                cout << bestRank[name2id[name]] << " " << courses[bestCourse[name2id[name]]] << "\n";
        }
    }
    return 0;
}