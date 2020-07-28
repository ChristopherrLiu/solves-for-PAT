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
#define maxe 110
using namespace std;

struct Time {
    int h,m,s;
    int totalSecond;
    void calTotalSecond() {
        totalSecond = h * 3600 + m * 60 + s;
    }
    bool operator< (const Time other) const {
        return h != other.h ? h < other.h : (m != other.m ? m < other.m : (s != other.s ? s < other.s : 0));
    }
};

struct Player {
    Time arrivingTime, servingTime;
    int waitingTime, p;
    int isVIP;
    bool operator< (const Player other) const {
        return arrivingTime < other.arrivingTime;
    }
};

int n;
Player players[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d:%d:%d %d %d", &players[i].arrivingTime.h, &players[i].arrivingTime.m, &players[i].arrivingTime.s, 
                &players[i].p, &players[i].isVIP);
            if(players[i].p > 120)
                players[i].p = 120;
        }
        sort(players, players + n);
        
    }
    return 0;
}