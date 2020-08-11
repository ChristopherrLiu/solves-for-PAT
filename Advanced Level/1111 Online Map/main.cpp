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
#define maxn 510
#define maxe 12
using namespace std;

int n, m, st, se;
int u, v, tag, le, ti;
int cnt , head[maxn], preLen[maxn], preTime[maxn];
int dist[maxn], times[maxn], nums[maxn];
bool vis[maxn];

struct Edge {
    int to, len, time, next;
    void set(int to_, int len_, int time_, int next_) {
        to = to_, len = len_, time = time_, next = next_;
    }
}edges[maxn * maxn];

struct StateLen {
    int to, len, time;
    void set(int to_, int len_, int time_) {
        to = to_, len = len_, time = time_;
    }
    bool operator< (const StateLen other) const {
        return len != other.len ? len > other.len : (
            time != other.time ? time > other.time : false
        );
    }
};

struct StateTime {
    int to, time, num;
    void set(int to_, int time_, int num_) {
        to = to_, time = time_, num = num_;
    }
    bool operator< (const StateTime other) const {
        return time != other.time ? time > other.time : (
            num != other.num ? num > other.num : false
        );
    }
};

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(preLen, -1, sizeof(preLen));
    memset(preTime, -1, sizeof(preTime));
}

void add(int from, int to, int len, int time) {
    edges[cnt].set(to, len, time, head[from]);
    head[from] = cnt++;
}

void dijkstraLen() {
    memset(dist, 0x3f, sizeof(dist));
    memset(times, 0x3f, sizeof(times));
    memset(vis, false, sizeof(vis));
    dist[st] = 0;
    times[st] = 0;
    StateLen a, b;
    a.set(st, 0, 0);
    priority_queue<StateLen> que;
    que.push(a);
    while(!que.empty()) {
        b= que.top();
        que.pop();
        if(vis[b.to])
            continue;
        vis[b.to] = true;
        for(int i = head[b.to]; i != -1; i = edges[i].next) {
            if(vis[edges[i].to])
                continue;
            if(dist[edges[i].to] > b.len + edges[i].len) {
                dist[edges[i].to] = b.len + edges[i].len;
                times[edges[i].to] = b.time + edges[i].time;
                preLen[edges[i].to] = b.to;
                StateLen newS;
                newS.set(edges[i].to, dist[edges[i].to], times[edges[i].to]);
                que.push(newS);
            }
            else if(dist[edges[i].to] == b.len + edges[i].len && times[edges[i].to] > b.time + edges[i].time) {
                times[edges[i].to] = b.time + edges[i].time;
                preLen[edges[i].to] = b.to;
                StateLen newS;
                newS.set(edges[i].to, dist[edges[i].to], times[edges[i].to]);
                que.push(newS);
            }
        }
    }
}

void dijkstraTime() {
    memset(nums, 0x3f, sizeof(nums));
    memset(times, 0x3f, sizeof(times));
    memset(vis, false, sizeof(vis));
    nums[st] = 0;
    times[st] = 0;
    StateTime a, b;
    a.set(st, 0, 0);
    priority_queue<StateTime> que;
    que.push(a);
    while(!que.empty()) {
        b= que.top();
        que.pop();
        if(vis[b.to])
            continue;
        vis[b.to] = true;
        for(int i = head[b.to]; i != -1; i = edges[i].next) {
            if(vis[edges[i].to])
                continue;
            if(times[edges[i].to] > b.time + edges[i].time) {
                times[edges[i].to] = b.time + edges[i].time;
                nums[edges[i].to] = b.num + 1;
                preTime[edges[i].to] = b.to;
                StateTime newS;
                newS.set(edges[i].to, times[edges[i].to], nums[edges[i].to]);
                que.push(newS);
            }
            else if(times[edges[i].to] == b.time + edges[i].time && nums[edges[i].to] > b.num + 1) {
                nums[edges[i].to] = b.num + 1;
                preTime[edges[i].to] = b.to;
                StateTime newS;
                newS.set(edges[i].to, times[edges[i].to], nums[edges[i].to]);
                que.push(newS);
            }
        }
    }
}

int main() {
    init();
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d %d %d", &u, &v, &tag, &le, &ti);
            if(!tag)
                add(v, u, le, ti);
            add(u, v, le, ti);
        }
        scanf("%d %d", &st, &se);
        dijkstraLen();
        dijkstraTime();
        int pt1 = se, pt2 = se;
        bool flag = true;
        vector<int> path;
        while(pt1 != -1 && pt2 != -1 && preLen[pt1] == preTime[pt2]) {
            pt1 = preLen[pt1], pt2 = preTime[pt2];
        }
        if(pt1 != -1 || pt2 != -1) 
            flag = false;
        if(flag) {
            printf("Distance = %d; Time = %d: ", dist[se], times[se]);
            pt1 = se;
            while(preLen[pt1] != -1)
                path.push_back(pt1), pt1 = preLen[pt1];
            path.push_back(pt1);
            for(int i = path.size() - 1; i >= 0; --i)
                if(i == 0)
                    printf("%d\n", path[i]);
                else
                    printf("%d -> ", path[i]);
        }
        else {
            printf("Distance = %d: ", dist[se]);
            pt1 = se;
            while(preLen[pt1] != -1)
                path.push_back(pt1), pt1 = preLen[pt1];
            path.push_back(pt1);
            for(int i = path.size() - 1; i >= 0; --i)
                if(i == 0)
                    printf("%d\n", path[i]);
                else
                    printf("%d -> ", path[i]);
            printf("Time = %d: ", times[se]);
            pt2 = se;
            path.clear();
            while(preTime[pt2] != -1)
                path.push_back(pt2), pt2 = preTime[pt2];
            path.push_back(pt2);
            for(int i = path.size() - 1; i >= 0; --i)
                if(i == 0)
                    printf("%d\n", path[i]);
                else
                    printf("%d -> ", path[i]);
        }
    }
    return 0;
}