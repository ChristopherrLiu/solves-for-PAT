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
#define maxe 10
using namespace std;

struct Time {
    int h, m, s, totalSeconds;
    void calTotalSeconds() {
        totalSeconds = h * 3600 + m * 60 + s;
    }
    void calHMS() {
        h = totalSeconds / 3600;
        m = (totalSeconds % 3600) / 60;
        s = (totalSeconds % 3600) % 60;
    }
    void print() {
        printf("%02d:%02d:%02d\n", h, m, s);
    }
};

struct Record {
    char plateNumber[maxe];
    Time time;
    int status;
    bool operator< (const Record other) const {
        return strcmp(plateNumber, other.plateNumber) != 0 ? strcmp(plateNumber, other.plateNumber) < 0 : (
            time.totalSeconds != other.time.totalSeconds ? time.totalSeconds  < other.time.totalSeconds : (
                status != other.status ? status < other.status : false
            )
        );
    }
};

struct Car {
    char plateNumber[maxe];
    Time in_time, out_time, stop_time;
    void calStopTime() {
        stop_time.totalSeconds = out_time.totalSeconds - in_time.totalSeconds;
        stop_time.calHMS();
    }
    bool operator< (const Car other) const {
        return out_time.totalSeconds != other.out_time.totalSeconds ? out_time.totalSeconds < other.out_time.totalSeconds : false;
    }
};

int n, k, cnt, cot, carId[maxn];
char s[maxe];
map<string, int> plate2id;
Record records[maxn];
Car cars[maxn];
Time qTime, stop_period[maxn];

int main() {
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s%d:%d:%d %s", records[i].plateNumber, &records[i].time.h, &records[i].time.m, &records[i].time.s, s);
            if(strcmp(s, "in") == 0)
                records[i].status = 0;
            else
                records[i].status = 1;
            records[i].time.calTotalSeconds();
        }
        sort(records, records + n);
        vector<int> maxPeriodId;
        vector<string> maxPeriodPlate;
        int tag = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(strcmp(records[i].plateNumber, records[i + 1].plateNumber))
                continue;
            else {
                if(records[i].status == records[i + 1].status || records[i].status == 1)
                    continue;
                strcpy(cars[cnt].plateNumber, records[i].plateNumber);
                cars[cnt].in_time = records[i].time;
                cars[cnt].out_time = records[i + 1].time;
                cars[cnt].calStopTime();
                int id = plate2id[cars[cnt].plateNumber];
                if(id == 0)
                    plate2id[cars[cnt].plateNumber] = id = ++cot;
                stop_period[id].totalSeconds += cars[cnt].stop_time.totalSeconds;
                carId[id] = cnt;
                if(stop_period[id].totalSeconds > tag) {
                    tag = stop_period[id].totalSeconds;
                    maxPeriodId.clear();
                    maxPeriodId.push_back(id);
                    maxPeriodPlate.clear();
                    maxPeriodPlate.push_back(cars[cnt].plateNumber);
                }
                else if(stop_period[id].totalSeconds == tag) {
                    maxPeriodId.push_back(id);
                    maxPeriodPlate.push_back(cars[cnt].plateNumber);
                }
                ++cnt, ++i;
            }
        }
        sort(cars, cars + cnt);
        int ans = 0, pt = 0;
        for(int i = 0; i < k; ++i) {
            scanf("%d:%d:%d", &qTime.h, &qTime.m, &qTime.s);
            qTime.calTotalSeconds();
            ans = 0;
            while(pt < cnt && cars[pt].out_time.totalSeconds <= qTime.totalSeconds)
                ++pt;
            for(int j = pt; j < cnt; ++j) {
                if(cars[j].in_time.totalSeconds <= qTime.totalSeconds)
                    ans++;
            }
            printf("%d\n",ans);
        }
        for(auto s : maxPeriodPlate) {
            printf("%s ", s.c_str());
        }
        stop_period[maxPeriodId[0]].calHMS();
        stop_period[maxPeriodId[0]].print();
    }
    return 0;
}