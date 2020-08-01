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
#define maxe 10010
using namespace std;

int n, m;
int seq[maxn];

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &seq[i]);
        }
        sort(seq, seq + n);
        int l = 0, r = n - 1, sum = seq[0] + seq[n - 1];
        bool flag = false;
        while(l < r) {
            if(sum < m) {
                sum -= seq[l];
                sum += seq[++l];
            }
            else if(sum > m) {
                sum -= seq[r];
                sum += seq[--r];
            }
            else {
                flag = true;
                printf("%d %d\n", seq[l], seq[r]);
                break;
            }
        }
        if(l == r) 
            puts("No Solution");
    }
    return 0;
}