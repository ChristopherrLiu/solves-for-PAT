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

int n, l, h, cnt, id, v, t;

struct Person {
    int type, virtue, talent, id;
    void getType() {
        if(virtue >= h && talent >= h) {
            type = 1;
        }
        else if(talent < h && virtue >= h) {
            type = 2;
        }
        else if(talent < h && virtue < h && virtue >= talent) {
            type = 3;
        }
        else {
            type = 4;
        }
    }
    bool operator< (const Person other) const {
        return type != other.type ? type < other.type : (
            virtue + talent != other.virtue + other.talent ? virtue + talent > other.virtue + other.talent : (
                virtue != other.virtue ? virtue > other.virtue : (
                    id != other.id ? id < other.id : false
                )
            )
        );
    }
};

Person persons[maxn];

int main() {
    while(~scanf("%d %d %d", &n, &l, &h)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d", &id, &v, &t);
            if(v >= l && t >= l) {
                persons[cnt].id = id;
                persons[cnt].virtue = v;
                persons[cnt].talent = t;
                persons[cnt].getType();
                cnt++;
            }
        }
        sort(persons, persons + cnt);
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; ++i) {
            printf("%08d %d %d\n", persons[i].id, persons[i].virtue, persons[i].talent);
        }
    }
    return 0;
}