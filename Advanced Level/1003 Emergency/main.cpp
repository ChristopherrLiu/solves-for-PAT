#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int maxe = maxn * maxn;

struct Edge {
    int to, length, next;
    void set(int to_, int length_, int next_) {
        to = to_, length = length_, next = next_;
    }
}edges[maxe];

struct State {
    int cityId, totalLength, totalTeamNumber;
    void set(int cityId_, int totalLength_, int totalTeamNumber_) {
        cityId = cityId_, totalLength = totalLength_, totalTeamNumber = totalTeamNumber_;
    }
    bool operator< (const State other) const {
        if(this->totalLength == other.totalLength)
            return this->totalTeamNumber < other.totalTeamNumber;
        return this->totalLength > other.totalLength;
    }
    bool operator== (const State other) const {
        return (this->totalLength == other.totalLength) && (this->totalLength == other.totalLength);
    }
};

int n, m, c1, c2, u, v, w;
int minDIst[maxn], nums[maxn], maxTeamNumber[maxn];
int cnt, head[maxn], teamNumbers[maxn];
bool vis[maxn];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int from, int to, int len) {
    edges[cnt].set(to, len, head[from]);
    head[from] = cnt++;
}

void dijkstra() {
    memset(minDIst, 0x3f, sizeof(minDIst));
    memset(maxTeamNumber, -1, sizeof(maxTeamNumber));
    memset(nums, 0, sizeof(nums));
    memset(vis, false, sizeof(vis));
    priority_queue<State>que;
    State initial;
    initial.set(c1, 0, teamNumbers[c1]);
    minDIst[c1] = 0;
    nums[c1] = 1;
    maxTeamNumber[c1] = teamNumbers[c1];
    que.push(initial);
    // State initial_;
    // initial_.set(c2, -1, 5);
    // que.push(initial_);
    // printf("%d\n", que.top().totalLength);
    // getchar();
    // getchar();
    while(!que.empty()) {
        State top = que.top();
        que.pop();
        if(vis[top.cityId])
            continue;
        vis[top.cityId] = true;
        for(int i = head[top.cityId]; i != -1; i = edges[i].next) {
            int to = edges[i].to;
            if(!vis[to]) {
                if(minDIst[to] > top.totalLength + edges[i].length) {
                    minDIst[to] = top.totalLength + edges[i].length;
                    nums[to] = nums[top.cityId];
                    maxTeamNumber[to] = top.totalTeamNumber + teamNumbers[to];
                    State nextState;
                    nextState.set(to, minDIst[to], maxTeamNumber[to]);
                    que.push(nextState);
                }
                else if(minDIst[to] == top.totalLength + edges[i].length && maxTeamNumber[to] < top.totalTeamNumber + teamNumbers[to]) {
                    nums[to] += nums[top.cityId];
                    maxTeamNumber[to] = top.totalTeamNumber + teamNumbers[to];
                    State nextState;
                    nextState.set(to, minDIst[to], maxTeamNumber[to]);
                    que.push(nextState);
                }
                else if(minDIst[to] == top.totalLength + edges[i].length) {
                    nums[to] += nums[top.cityId];
                }
            }
        }
    }
}

int main() {
    while(~scanf("%d %d %d %d", &n, &m, &c1, &c2)) {
        init();
        for(int i = 0; i < n; ++i)
            scanf("%d", &teamNumbers[i]);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        dijkstra();
        printf("%d %d\n", nums[c2], maxTeamNumber[c2]);
    }
    return 0;
}