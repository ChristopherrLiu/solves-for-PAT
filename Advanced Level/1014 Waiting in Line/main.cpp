#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 1010;

struct Time {
    int h, m, id, tag;
    void set(int h_, int m_, int id_, int tag_) {
        h = h_, m = m_, id = id_, tag = tag_;
    }
    void addMinute(int m_) {
        this->m += m_;
        this->h += (this->m / 60);
        this->m %= 60;
    }
    void print() {
        if(this->tag)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", this->h, this->m);
    }
    bool operator< (const Time other) const {
        if(this->h > other.h)
            return true;
        else if(this->h == other.h && this->m > other.m)
            return true;
        return false;
    }
    bool operator<= (const Time other) const {
        if(!(*this < other))
            return true;
        return false;
    }
};

struct Window {
    int capacity, id;
    void set(int capacity_, int id_) {
        this->capacity = capacity_, this->id = id_;
    }
    bool operator< (const Window other) const {
        if(this->capacity < other.capacity)
            return true;
        else if(this->capacity == other.capacity && this->id > other.id)
            return true;
        return false;
    }
};

int n,m,k,q,qi;
int serviceTime[maxn], windowIds[maxn];
Time windowDone[maxn], customersDone[maxn];
Window windows[maxn];

void solve() {
    priority_queue<Window> availableWindow;
    priority_queue<Time> doneList;
    for(int i = 1; i <= n; ++i) {
        windows[i].set(m, i);
        windowDone[i].set(8, 0, -1, 0);
        availableWindow.push(windows[i]);
    }
    Time initial, cur, tag;
    windowIds[1] = 1;
    tag.set(17, 0, -1, 0);
    int curId = 1;
    Window window;

    while(!availableWindow.empty() && curId <= k) {
        window = availableWindow.top();
        availableWindow.pop();

        Time newItem;
        if(tag <= windowDone[window.id])
            newItem.set(windowDone[window.id].h, windowDone[window.id].m, curId, 1);
        else
            newItem.set(windowDone[window.id].h, windowDone[window.id].m, curId, 0);
        newItem.addMinute(serviceTime[curId]);
        windowDone[window.id].set(newItem.h, newItem.m, newItem.id, newItem.tag);
        windowIds[curId] = window.id;

        curId++;
        windows[window.id].capacity--;
        if(windows[window.id].capacity)
            availableWindow.push(windows[window.id]);
        doneList.push(newItem);
    }

    while(!doneList.empty()) {
        cur = doneList.top();
        doneList.pop();
        customersDone[cur.id] = cur;
        windows[windowIds[cur.id]].capacity++;
        if(windows[windowIds[cur.id]].capacity == 1)
            availableWindow.push(windows[windowIds[cur.id]]);

        if(curId > k)
            continue;

        window = availableWindow.top();
        availableWindow.pop();
        Time newItem;
        if(tag <= windowDone[window.id])
            newItem.set(windowDone[window.id].h, windowDone[window.id].m, curId, 1);
        else
            newItem.set(windowDone[window.id].h, windowDone[window.id].m, curId, 0);
        newItem.addMinute(serviceTime[curId]);
        windowDone[window.id].set(newItem.h, newItem.m, newItem.id, newItem.tag);
        windowIds[curId] = window.id;
        curId++;
        windows[window.id].capacity--;
        if(windows[window.id].capacity)
            availableWindow.push(windows[window.id]);
        doneList.push(newItem);
 
    }
}

int main() {
    while(~scanf("%d %d %d %d", &n, &m, &k, &q)) {
        for(int i = 1; i <= k; ++i) 
            scanf("%d", &serviceTime[i]);
        solve();
        for(int i = 0; i < q; ++i) {
            scanf("%d", &qi);
            customersDone[qi].print();
        }
    }
    return 0;
}