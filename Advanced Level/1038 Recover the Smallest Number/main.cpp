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
#define maxe 250010
using namespace std;

struct Segment {
    string data;
    bool operator< (const Segment other) const {
        return data + other.data < other.data + data;
    }
};

int n;
Segment segments[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            cin >> segments[i].data;
        }
        sort(segments, segments + n);
        // int pl = 0, pr = 0;
        // while(pl < n) {
        //     while(pr < n && segments[pr].data[0] == segments[pl].data[0])
        //         ++pr;
        //     bool flag = true;
        //     while(flag) {
        //         flag = false;
        //         for(int i = pl + 1; i < pr; ++i) {
        //             if(segments[i - 1].data + segments[i].data > segments[i].data + segments[i - 1].data) {
        //                 swap(segments[i - 1].data, segments[i].data);
        //                 flag = true;
        //             }
        //         }
        //     }
        //     pl = pr;
        // }
        string ans;
        for(int i = 0; i < n; ++i)
            ans += segments[i].data;
        int i = 0;
        while(i < ans.length() && ans[i] == '0')
            ++i;
        if(i == ans.length())
            cout << "0" << "\n";
        else
            cout << ans.substr(i, ans.length()) << "\n";
    }
    return 0;
}