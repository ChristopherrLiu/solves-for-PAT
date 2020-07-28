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

double mat[3][3];
char res[3] = {'W', 'T', 'L'};

pair<double, int> solve(int rowId) {
    double odd = 0;
    int resultId = 0;
    for(int i = 0; i < 3; ++i) {
        if(mat[rowId][i] > odd) {
            odd = mat[rowId][i];
            resultId = i;
        }
    }
    return make_pair(odd, resultId);
}

int main() {
    while(cin >> mat[0][0] >> mat[0][1] >> mat[0][2]) {
        cin >> mat[1][0] >> mat[1][1] >> mat[1][2];
        cin >> mat[2][0] >> mat[2][1] >> mat[2][2];
        double ans = 1;
        string resultList;
        for(int i = 0; i < 3; ++i) {
            pair<double, int> curRes = solve(i);
            if(i > 0)
                resultList += ' ';
            resultList += res[curRes.second];
            ans *= curRes.first;
        }
        ans = (ans * 0.65 - 1) * 2;
        cout << resultList << " ";
        printf("%.2f\n", ans);
    }
    return 0;
}