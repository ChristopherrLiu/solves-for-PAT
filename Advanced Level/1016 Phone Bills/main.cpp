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
#define maxn 1010
#define maxe 1000010
using namespace std;

int cents[maxn], centsSum;

struct Time {
    int month, day, hour, minute;
    void set(int mo, int da, int ho, int mi) {
        month = mo, day = da, hour = ho, mi = minute;
    }
    void print() {
        printf("%d:%d:%d:%d\n", month, day, hour, minute);
    }
    void addOneMinute() {
        minute += 1;
       if(minute >= 60) {
            hour += 1;
            minute = 0;
            if(hour >= 24) {
                day += 1;
                hour = 0;
            }
       }
    }
    bool operator< (const Time other) const {
        if(month < other.month)
            return true;
        else if(month == other.month && day < other.day)
            return true;
        else if(month == other.month && day == other.day && hour < other.hour)
            return true;
        else if(month == other.month && day == other.day && hour == other.hour && minute < other.minute)
            return true;
        return false;
    }
    bool operator== (const Time other) const {
        return (month == other.month && day == other.day && hour == other.hour && minute == other.minute);
    }
    bool operator<= (const Time other) const {
        return *this < other || *this == other;
    }
    int operator- (const Time other) {
        int minutes1 = month * 30 * 24 * 60 + day * 24 * 60 + hour * 60 + minute;
        int minutes2 = other.month * 30 * 24 * 60 + other.day * 24 * 60 + other.hour * 60 + other.minute;
        return minutes1 - minutes2;
    }
};

struct Record {
    string name;
    Time time;
    int state;
    bool operator< (const Record other) const {
        return time < other.time;
    }
};

struct Call {
    Time start, end;
    int totalMinutes, cent;
    void calCent() {
        cent = 0;
        int starthsum = 0, endhsum = 0; 
        for(int i = 0; i < start.hour; ++i) {
            starthsum += cents[i] * 60;
        }
        for(int i = 0; i < end.hour; ++i) {
            endhsum += cents[i] * 60;
        }
        // cout << start.day << " " << starthsum << " " << end.day << " " << endhsum<< endl;
        // cout << cents[start.hour] * start.minute << " " << cents[end.hour] * end.minute << endl;
        cent = -(start.day * centsSum + starthsum + cents[start.hour] * start.minute - 
        end.day * centsSum - endhsum - cents[end.hour] * end.minute);
    }
    void print() {
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%d.%d\n", start.day, start.hour, start.minute,
            end.day, end.hour, end.minute, totalMinutes, cent / 100, cent % 100);
    }
};

struct Customer {
    string name;
    vector<Call> calls[13];
    int totalAmounts[13];
    void print() {
        for(int i = 1; i <= 12; ++i) {
            if(!totalAmounts[i])
                continue;
            cout << name << " ";
            printf("%02d\n", i);
            for(auto call : calls[i])
                call.print();
            printf("Total amount: $%d.%d\n", totalAmounts[i] / 100, totalAmounts[i] % 100);
        }
    }
    bool operator< (const Customer other) const {
        return name < other.name;
    }
};

int pre[maxn];
string state;
Record records[maxn];
Customer customers[maxn];
map<string, int> name2id;

int main() {
    int n;
    while(true) {
        for(int i = 0; i < 24; ++i) {
            scanf("%d", &cents[i]);
            centsSum += cents[i] * 60;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            cin >> records[i].name;
            scanf("%d:%d:%d:%d", &records[i].time.month, &records[i].time.day, &records[i].time.hour, &records[i].time.minute);
            cin >> state;
            if(state == "on-line")
                records[i].state = 1;
            else
                records[i].state = 2;
        }
        int cnt = 0;
        memset(pre, -1, sizeof(pre));
        sort(records, records + n);
        // for(int i = 0; i < n; ++i) {
        //     cout << records[i].name << endl;
        //     records[i].time.print();
        //     cout << records[i].state << endl;
        // }
        // getchar();
        // getchar();
        for(int i = 0; i < n; ++i) {
            if(name2id[records[i].name] == 0)
                name2id[records[i].name] = ++cnt;
            int id = name2id[records[i].name];
            customers[id].name = records[i].name;
            // cout << id << endl;
            if(pre[id] == -1) {
                if(records[i].state == 1) {
                    pre[id] = i;
                }
            }
            else {
                if(records[i].state == 1) {
                    pre[id] = i;
                }
                else {
                    // cout << records[i].name << endl;
                    // records[i].time.print();
                    // getchar();
                    // getchar();
                    Call call;
                    call.start = records[pre[id]].time;
                    call.end = records[i].time;
                    call.totalMinutes = call.end - call.start;
                    // cout << pre[id] << endl;
                    // call.start.print();
                    // call.end.print();
                    // cout << call.totalMinutes << endl;
                    // getchar();
                    // getchar();
                    call.calCent();
                    customers[id].calls[call.start.month].push_back(call);
                    customers[id].totalAmounts[call.start.month] += call.cent;
                    pre[id] = -1;
                }
            }
        }
        sort(customers + 1, customers + cnt + 1);
        for(int i = 1; i <= cnt; ++i) {
            customers[i].print();
        }
    }
    return 0;
}