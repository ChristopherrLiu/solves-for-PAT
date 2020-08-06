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
#define maxe 110
#define maxk 6
using namespace std;

struct School {
    int quota, curRank;
    vector<int> stduentIds;
};

struct Person {
    int id, rank;
    int ge, gi;
    int choices[maxk];
    bool operator< (const Person other) const {
        return ge + gi != other.ge + other.gi ? ge + gi > other.ge + other.gi : (
            ge != other.ge ? ge > other.ge : (
                id != other.id ? id < other.id : false
            )
        );
    }
};

int n, m, k;
School schools[maxe];
Person persons[maxn];

int main() {
    while(~scanf("%d %d %d", &n, &m, &k)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d", &schools[i].quota);
            schools[i].curRank = -1;
        }
        for(int i = 0; i < n; ++i) {
            persons[i].id = i;
            scanf("%d %d", &persons[i].ge, &persons[i].gi);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &persons[i].choices[j]);
            }
        }
        sort(persons, persons + n);
        int rak = 1, sameRakNum = 1;
        for(int i = 0; i< n; ++i) {
            if(persons[i].ge + persons[i].gi == persons[i - 1].ge + persons[i - 1].gi && persons[i].ge == persons[i - 1].ge) {
                sameRakNum++;
            }
            else {
                rak += sameRakNum;
                sameRakNum = 1;
            }

            for(int j = 0; j < k; ++j) {
                int curSchool = persons[i].choices[j];
                if(schools[curSchool].quota) {
                    schools[curSchool].quota--;
                    schools[curSchool].stduentIds.push_back(persons[i].id);
                    schools[curSchool].curRank = rak;
                    break;
                }
                else if(schools[curSchool].curRank == rak) {
                    schools[curSchool].stduentIds.push_back(persons[i].id);
                    schools[curSchool].curRank = rak;
                    break;
                }
            }
        }

        for(int i = 0; i < m; ++i) {
            if(schools[i].stduentIds.size() == 0) {
                printf("\n");
            }
            else {
                sort(schools[i].stduentIds.begin(), schools[i].stduentIds.end());
                int sz = schools[i].stduentIds.size();
                for(int j = 0; j < sz; ++j) {
                    printf("%d%c", schools[i].stduentIds[j], j == sz - 1 ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}