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
#define maxe 1010
#define DEBUG
using namespace std;

struct Testee {
    string id;
    string level, sitenumber, date;
    int score;
    void decode() {
        level = id.substr(0, 1);
        sitenumber = id.substr(1, 3);
        date = id.substr(4, 6);
    }
    bool operator< (const Testee other) const {
        return score != other.score ? score > other.score : (
            id != other.id ? id < other.id : false
        );
    }
};

struct Site {
    string id;
    int peoplenumber, totalscore;
    bool operator< (const Site other) const {
        return peoplenumber != other.peoplenumber ? peoplenumber > other.peoplenumber : (
            id != other.id ? id < other.id : false
        );
    }
};

struct Date {
    string date;
    vector<Site> sites;
}; 

int n, m, qid, siteTot, dateTot;
string qinfo;
Testee testees[maxn];
Site sites[maxn];
Date dates[maxn];
map<string, int> site2id, date2id;

int main() {
    cin >> n >> m;
    int sid, did;
    bool find;
    for(int i = 0; i < n; ++i) {
        cin >> testees[i].id >> testees[i].score;
        testees[i].decode();
        sid = site2id[testees[i].sitenumber];
        if(sid == 0)
            sid = site2id[testees[i].sitenumber] = ++siteTot;
        sites[sid].id = testees[i].sitenumber;
        sites[sid].peoplenumber++;
        sites[sid].totalscore += testees[i].score;
        did = date2id[testees[i].date];
        if(did == 0)
            did = date2id[testees[i].date] = ++dateTot;
        dates[did].date = testees[i].date;
        find = false;
        for(int j = 0; j < dates[did].sites.size(); ++j) {
            if(dates[did].sites[j].id == testees[i].sitenumber) {
                dates[did].sites[j].peoplenumber++;
                find = true;
                break;
            }
        }
        if(!find) {
            Site newsite;
            newsite.id = testees[i].sitenumber;
            newsite.peoplenumber = 1;
            dates[did].sites.push_back(newsite);
        }
    }
    sort(testees, testees + n);
    for(int i = 0; i < m; ++i) {
        cin >> qid >> qinfo;
        cout << "Case " << i + 1 << ": "<< qid << " " << qinfo << "\n";
        if(qid == 1) {
            find = false;
            for(int i = 0; i < n; ++i) {
                if(testees[i].level == qinfo)
                    find = true, cout << testees[i].id << " " << testees[i].score << "\n";
            }
            if(!find)
                cout << "NA" << "\n";
        }
        else if(qid == 2) {
            int id = site2id[qinfo];
            if(id == 0)
                cout << "NA" << "\n";
            else
                cout << sites[site2id[qinfo]].peoplenumber << " " << sites[site2id[qinfo]].totalscore << "\n";
        }
        else {
            int id = date2id[qinfo];
            if(id == 0)
                cout << "NA" << "\n";
            else {
                sort(dates[id].sites.begin(), dates[id].sites.end());
                for(auto site : dates[id].sites) {
                    cout << site.id << " " << site.peoplenumber << "\n";
                }
            }
        }
    }
    #ifdef DEBUG
        getchar();
        getchar();
    #endif
    return 0;
}