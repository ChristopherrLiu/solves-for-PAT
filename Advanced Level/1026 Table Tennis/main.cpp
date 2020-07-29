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
    void addMinute(int n) {
        m += n;
        if(m >= 60) {
            h += m / 60;
            m %= 60;
        }
        calTotalSecond();
    }
    bool operator< (const Time other) const {
        return h != other.h ? h < other.h : (m != other.m ? m < other.m : (s != other.s ? s < other.s : false));
    }
};

struct Player {
    Time arrivingTime;
    int p;
    int isVIP;
    bool operator< (const Player other) const {
        return arrivingTime < other.arrivingTime;
    }
};

struct Result {
    Time arrivingTime, servingTime;
    int waitingTime;
    bool operator< (const Result other) const {
        return servingTime < other.servingTime;
    }
};

struct Table {
    Time openTime;
    int isVIP, serveNum;
};

int n, k, m, v;
Player players[maxn];
Table tables[maxe];
Result results[maxn];
bool isDone[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d:%d:%d %d %d", &players[i].arrivingTime.h, &players[i].arrivingTime.m, &players[i].arrivingTime.s, 
                &players[i].p, &players[i].isVIP);
            players[i].arrivingTime.calTotalSecond();
            if(players[i].p > 120)
                players[i].p = 120;
        }
        sort(players, players + n);
        for(int i = 0; i < n; ++i) {
            if(players[i].arrivingTime.totalSecond >= 21 * 3600) {
                n = i;
                break;
            }
        }
        scanf("%d %d", &k, &m);
        for(int i = 0; i < k; ++i) {
            tables[i].openTime.h = 8, tables[i].openTime.m = 0, tables[i].openTime.s = 0;
            tables[i].openTime.calTotalSecond();
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d", &v);
            tables[v - 1].isVIP = 1;
        }
        int resultNum = 0;
        for(int i = 0; i < n; ++i) {
            int tag = tables[0].openTime.totalSecond, tableId = 0;
            for(int j = 1; j < k; ++j) {
                if(tables[j].openTime.totalSecond < tag) {
                    tag = tables[j].openTime.totalSecond;
                    tableId= j;
                }
            }
            if(tag >= 21 * 3600)
                break;
            int playerId = 0;
            while(playerId < n && isDone[playerId])
                playerId++;
            
            if(tag <= players[playerId].arrivingTime.totalSecond) {
                for(int j = 0; j < k; ++j) {
                    if(tables[j].openTime.totalSecond <= players[playerId].arrivingTime.totalSecond) {
                        tableId = j;
                        break;
                    }
                }
                if(players[playerId].isVIP) {
                    for(int j = tableId; j < k; ++j) {
                        if(tables[j].isVIP) {
                            if(tables[j].openTime.totalSecond <= players[playerId].arrivingTime.totalSecond) {
                                tableId= j;
                                break;
                            }
                        }
                    }
                }
            }
            else if(tables[tableId].isVIP) {
                for(int j = playerId; j < n && players[j].arrivingTime.totalSecond <= tag; ++j) {
                    if(players[j].isVIP && !isDone[j]) {
                        playerId = j;
                        break;
                    }
                }
            }
            results[resultNum].arrivingTime = players[playerId].arrivingTime;
            results[resultNum].servingTime = players[playerId].arrivingTime.totalSecond < tables[tableId].openTime.totalSecond ? tables[tableId].openTime : players[playerId].arrivingTime;
            results[resultNum].waitingTime = results[resultNum].servingTime.totalSecond - results[resultNum].arrivingTime.totalSecond;
            isDone[playerId] = true;
            ++resultNum;
            tables[tableId].openTime = results[resultNum - 1].servingTime;
            tables[tableId].openTime.addMinute(players[playerId].p);
            tables[tableId].serveNum++;
        }
        sort(results, results + resultNum);
        for(int i = 0; i < resultNum; ++i) {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", results[i].arrivingTime.h, results[i].arrivingTime.m, results[i].arrivingTime.s
            , results[i].servingTime.h, results[i].servingTime.m, results[i].servingTime.s, ((results[i].waitingTime + 30) / 60));
        }
        printf("%d", tables[0].serveNum);
        for(int i = 1; i < k; ++i)
            printf(" %d", tables[i].serveNum);
        printf("\n");
    }
    return 0;
}