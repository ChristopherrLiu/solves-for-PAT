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
#define maxn 100010
#define maxe 110
using namespace std;

int n, c;

struct Record {
    string datas[4];
    bool operator< (const Record other) const {
        if(c == 1)
            return datas[c] < other.datas[c];
        else{
            if(datas[c] < other.datas[c])
                return true;
            else if(datas[c] == other.datas[c] && datas[1] < other.datas[1])
                return true;
            return false;
        }
    }
    void print() {
        cout << datas[1] << " " << datas[2] << " " << datas[3] << "\n";
    }
}records[maxn];

int main() {
    while(cin >> n >> c) {
        for(int i = 0; i < n; ++i) {
            cin >> records[i].datas[1] >> records[i].datas[2] >> records[i].datas[3];
        }
        sort(records, records + n);
        for(int i = 0; i < n; ++i)
            records[i].print();
    }
    return 0;
}