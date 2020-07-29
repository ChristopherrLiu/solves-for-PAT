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
#define maxn 81
#define maxe 250010
using namespace std;

string inputs;
string outputs[maxn];

int main() {
    while(cin >> inputs) {
        int n = inputs.length();
        int n1, n2, n3;
        n1 = n3 = floor((n + 2) * 1.0 / 3);
        n2 = ceil((n + 2) * 1.0 / 3);
        for(int i = 0; i < n1; ++i) {
            outputs[i] += inputs[i];
            for(int j = 1; j < n2 - 1; ++j)
                if(i != n1 - 1)
                    outputs[i] += ' ';
                else
                    outputs[i] += inputs[j + i];
            outputs[i] += inputs[n - 1 - i];
        }
        for(int i = 0; i < n1; ++i)
            cout << outputs[i] << endl;
    }
    return 0;
}