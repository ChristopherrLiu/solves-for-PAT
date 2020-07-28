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
#define maxn 30010
#define maxe 110
using namespace std;

struct Testee {
    string registration_number;
    int score;
    int final_rank, location_number, local_rank;
    bool operator< (const Testee other) const {
        if(score > other.score)
            return true;
        else if(score == other.score && registration_number < other.registration_number)
            return true;
        return false;
    }
};

int n, k, cnt, lr[maxe], lpre[maxe], lnum[maxe];
Testee testees[maxn];

int main() {
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            lr[i] = 1;
            lpre[i] = -1;
            lnum[i] = 0;
            cin >> k;
            for(int j = 0; j < k; ++j) {
                cin >> testees[cnt].registration_number >> testees[cnt].score;
                testees[cnt++].location_number = i;
            }
        }
        sort(testees, testees + cnt);
        int fr = 1;
        for(int i = 0; i < cnt; ++i) {
            if(i > 0 && testees[i].score != testees[i - 1].score)
                fr = i + 1;
            testees[i].final_rank = fr;
            if(lpre[testees[i].location_number] == -1) {
                lpre[testees[i].location_number] = testees[i].score;
                lnum[testees[i].location_number] = 1;
            }
            else if(lpre[testees[i].location_number] != testees[i].score) {
                lpre[testees[i].location_number] = testees[i].score;
                lr[testees[i].location_number] += lnum[testees[i].location_number];
                lnum[testees[i].location_number] = 1;
            }
            else {
                ++lnum[testees[i].location_number];
            }
            testees[i].local_rank = lr[testees[i].location_number];
        }
        cout << cnt << "\n";
        for(int i = 0; i < cnt; ++i) {
            cout << testees[i].registration_number << " " << testees[i].final_rank << " " 
                << testees[i].location_number << " " << testees[i].local_rank << "\n";
        }
    }
    return 0;
}