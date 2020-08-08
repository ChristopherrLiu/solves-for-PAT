#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#define maxn 1300
#define maxe 130
#define maxk 65
using namespace std;

int m, n, l, t, cnt, ans;
int slice[maxk][maxn][maxe];
bool vis[maxk][maxn][maxe];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<pair<int, pair<int, int> > >que;

bool check(int x, int y, int z) {
    if(x < 0 || x >= m)
        return false;
    if(y < 0 || y >= n)
        return false;
    if(z < 0 || z >= l)
        return false;
    return true;
}

void bfs(int cx, int cy, int cz) {
    while(que.size())
        que.pop();
    que.push(make_pair(cx, make_pair(cy, cz)));
    pair<int, pair<int, int> > cur;
    while(que.size()) {
        cur = que.front();
        cx = cur.first, cy = cur.second.first, cz = cur.second.second;
        que.pop();
        if(vis[cz][cx][cy])
            continue;
        vis[cz][cx][cy] = true;
        cnt++;
        for(int i = 0; i < 6; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];
            if(check(nx, ny, nz) && !vis[nz][nx][ny] && slice[nz][nx][ny])
                que.push(make_pair(nx, make_pair(ny, nz)));
        }
    }
}

int main() {
    while(~scanf("%d %d %d %d", &m, &n, &l, &t)) {
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j < m; ++j) {
                for(int k = 0; k < n; ++k) {
                    scanf("%d", &slice[i][j][k]);
                }
            }
        }
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j < m; ++j) {
                for(int k = 0; k < n; ++k) {
                    if(!vis[i][j][k] && slice[i][j][k]) {
                        cnt = 0;
                        bfs(j, k, i);
                        if(cnt >= t)
                            ans += cnt;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}