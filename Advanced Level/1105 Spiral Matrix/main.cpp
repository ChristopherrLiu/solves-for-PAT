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
#define maxe 110
using namespace std;

int N, m, n;
int seq[maxn], mat[maxe][maxe];

int main() {
    while(~scanf("%d", &N)) {
        m = ceil(sqrt(N * 1.0));
        while(N % m != 0)
            ++m;
        n = N / m;
        for(int i = 0; i < N; ++i)
            scanf("%d", &seq[i]);
        sort(seq, seq + N);
        int cirNum = ceil(n * 1.0 / 2), pt = N - 1;
        for(int i = 0; i < cirNum; ++i) {
            int x = i, y = i;
            while(y < n && mat[x][y] == 0) {
                mat[x][y] = seq[pt--];
                ++y;
            }
            --y;
            ++x;
            while(x < m && mat[x][y] == 0) {
                mat[x][y] = seq[pt--];
                ++x;
            }
            --x;
            --y;
            while(y >= 0 && mat[x][y] == 0) {
                mat[x][y] = seq[pt--];
                --y;
            }
            ++y;
            --x;
            while(x >= 0 && mat[x][y] == 0) {
                mat[x][y] = seq[pt--];
                --x;
            }
        }
        for(int i = 0 ; i < m; ++i)
            for(int j = 0; j < n; ++j)
                printf("%d%c", mat[i][j], j == n - 1 ? '\n' : ' ');
    }
    return 0;
}