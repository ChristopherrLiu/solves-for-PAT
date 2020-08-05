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
#define maxe 6
using namespace std;

struct Person {
    int id;
    int score[maxe], tScore;
    int AC, nSub;
    void init() {
        for(int i = 1; i <= 5; ++i)
            score[i] = -2;
        tScore = AC = 0;
        nSub = 0;
    }
    bool operator< (const Person other) const {
        return nSub != other.nSub ? nSub > other.nSub : (
        tScore != other.tScore ? tScore > other.tScore : (
            AC != other.AC ? AC > other.AC : (
                id != other.id ? id < other.id: false
            )
        ));
    }
};

int n, k, m, cnt, curId, id, pId, sc;
int score[maxe];
Person persons[maxn];

int main() {
    while(~scanf("%d %d %d", &n, &k, &m)) {
        for(int i = 1; i <= n; ++i)
            persons[i].init();
        for(int i = 1; i <= k; ++i)
            scanf("%d", &score[i]);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &id, &pId, &sc);
            curId = id;

            persons[curId].id = id;
            if(persons[curId].score[pId] != -2 && sc > persons[curId].score[pId]) {
                if(sc != -1)
                    persons[curId].nSub = 1;
                persons[curId].tScore -= persons[curId].score[pId];
                persons[curId].score[pId] = sc;
                persons[curId].tScore += sc;
                if(sc == score[pId])
                    persons[curId].AC++;
            }
            else if(persons[curId].score[pId] == -2){
                if(sc != -1)
                    persons[curId].nSub = 1;
                if(sc == -1)
                    sc = 0;
                persons[curId].score[pId] = sc;
                persons[curId].tScore += sc;
                if(sc == score[pId])
                    persons[curId].AC++;
            }
            else if(sc == 0 && persons[curId].score[pId] == 0) {
                persons[curId].nSub = 1;
            }
        }
        sort(persons + 1, persons + n + 1);
        int rak = 1, sameRank = 1;
        for(int i = 1; i <= n; ++i) {
            if(i > 1) {
                if(persons[i].tScore != persons[i - 1].tScore)
                    rak += sameRank, sameRank = 1;
                else
                    sameRank++;
            }
            if(persons[i].nSub == 0)
                break;
            printf("%d %05d %d", rak, persons[i].id, persons[i].tScore);
            for(int j = 1; j <= k; ++j) {
                if(persons[i].score[j] == -2)
                    printf(" -");
                else
                    printf(" %d", persons[i].score[j]);
            }
            printf("\n");
        }
    }
    return 0;
}