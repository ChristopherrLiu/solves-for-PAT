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
#define maxn 10010
#define maxe 1000010
using namespace std;

struct Customer {
    int ah,am,as;
    double aTime;
    int pTime;
    void calaTime() {
        aTime = ah * 60 + am + as * 1.0 / 60;
    }
    bool operator< (const Customer other) const {
        if(aTime < other.aTime)
            return true;
        return false;
    }
    bool operator== (const Customer other) const {
        if(aTime == other.aTime)
            return true;
        return false;
    }
};

// struct Window {
//     queue<double> customerList;
// };

int n,k;
double totalWaitTime;
Customer customers[maxn];
double customerList[maxn];

int main() {
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d:%d:%d %d", &customers[i].ah, &customers[i].am, &customers[i].as, &customers[i].pTime);
            customers[i].calaTime();
        }
        sort(customers, customers + n);
        Customer temp;
        temp.ah = 8, temp.am = 0, temp.as = 0;
        temp.calaTime();
        for(int i = 0; i < n; ++i) {
            if(customers[i].ah == 17 && customers[i].am == 0 && customers[i].as >= 1) {
                n = i;
                break;
            }
            if(customers[i] < temp) {
                totalWaitTime += temp.aTime - customers[i].aTime;
                customers[i].ah = 8, customers[i].am = 0, customers[i].as = 0;
                customers[i].calaTime();
            }
        }
        // cout << totalWaitTime << endl;
        for(int i = 0; i < k; ++i) {
            customerList[i] = customers[i].aTime + customers[i].pTime;
        }
        int pt = k;
        while(pt < n) {
            int currentWindow;
            double tag = 1e9;
            for(int i = 0; i < k; ++i) {
                if(customerList[i] < tag) {
                    tag = customerList[i];
                    currentWindow = i;
                }
            }
            // cout << currentWindow << endl;
            double currentWaitTime = customers[pt].aTime - customerList[currentWindow];
            if(currentWaitTime < 0) {
                // cout << currentWaitTime << endl;
                // cout << customerList[currentWindow] << endl;
                totalWaitTime += (-currentWaitTime);
                customerList[currentWindow] += customers[pt].pTime; 
            }
            else {
                customerList[currentWindow] = customers[pt].aTime + customers[pt].pTime;
            }
            pt++;
        }
        // cout << totalWaitTime << endl;
        printf("%.1f\n", totalWaitTime / (n * 1.0));
    }
    return 0;
}