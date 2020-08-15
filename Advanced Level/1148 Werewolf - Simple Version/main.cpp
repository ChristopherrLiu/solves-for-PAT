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
#define maxn 1010
#define maxe 22
using namespace std;

int n, seqs[maxn], tag[maxn];
int p1, p2, ans1, ans2;

bool permutation() {
    ++p2;
    if(p2 > n) {
        ++p1, p2 = p1 + 1;
        if(p1 > n)
            return false;
    }
    return true;
}

int main() {
    while(~scanf("%d", &n)) {
        p1 = 1, p2 = 1;
        ans1 = -1, ans2 = -1;
        for(int i = 1 ; i <= n; ++i)
            scanf("%d", &seqs[i]);
        while(permutation()) {
            memset(tag, 0, sizeof(tag));
            bool flag = true;
            for(int i = 1; i <= n; ++i) {
                if(i == p1 || i == p2) {
                    if(seqs[i] > 0) {
                        if(tag[seqs[i]] == 1) {
                            flag = false;
                            break;
                        }
                        tag[seqs[i]] = -1;
                    }
                    else {
                        if(tag[abs(seqs[i])] == -1) {
                            flag = false;
                            break;
                        }
                        tag[abs(seqs[i])] = 1;
                    }
                }
                else if(seqs[i] < 0) {
                    if(tag[abs(seqs[i])] == 1) {
                        flag = false;
                        break;
                    }
                    tag[abs(seqs[i])] = -1;
                }
                else {
                    if(tag[seqs[i]] == -1) {
                        flag = false;
                        break;
                    }
                    tag[seqs[i]] = 1;
                }
            }
            if(flag) {
                int wolfNum = 0, perNum = 0;
                for(int i = 1; i <= n; ++i)
                    if(tag[i] == -1)
                        wolfNum++;
                    else if(tag[i] == 1)
                        perNum++;
                // if(p1 == 1 && p2 == 5) 
                //     cout << wolfNum << endl;
                if(wolfNum > 2 || (wolfNum < 2 && 2 + perNum > n))
                    continue;
                // cout << p1 << " " << p2 << endl;
                bool first = true;
                int cp1 = -1, cp2 = -1;
                for(int i = 1; i <= n; ++i) {
                    if(tag[i] == -1) {
                        if(first) {
                            cp1 = i;
                            first = false;
                        }
                        else {
                            cp2 = i;
                            break;
                        }
                    }
                }
                if(cp1 == -1 || cp2 == -1) {
                    for(int i = 1; i <= n; ++i) {
                        if(tag[i] == 0) {
                            if(first) {
                                cp1 = i;
                                first = false;
                            }
                            else {
                                cp2 = i;
                                break;
                            }
                        }
                    }   
                }
                if(cp1 > cp2)
                    swap(cp1, cp2);
                if((cp1 == p1 && cp2 != p2) || (cp1 != p1 && cp2 == p2)) {
                    if(cp1 < ans1 || ans1 == -1) {
                        ans1 = cp1, ans2 = cp2;
                    }
                    else if(cp1 == ans1 && cp2 < ans2) {
                        ans1 = cp1, ans2 = cp2;
                    }
                }
                
            }
        }
        if(ans1 == -1)
            puts("No Solution");
        else
            printf("%d %d\n", ans1, ans2);
    }
    return 0;
}