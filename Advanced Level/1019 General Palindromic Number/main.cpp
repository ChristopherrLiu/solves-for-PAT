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
#define maxn 510
#define maxe 250001
using namespace std;

int n, b;
string nums;
vector<int>ans;

int main() {
    while(~scanf("%d %d", &n, &b)) {
        nums.clear();
        ans.clear();
        int temp = b;
        while(n) {
            nums += (n % b);
            ans.push_back(n % b);
            n /= temp;
        }
        string anotherNums = nums;
        reverse(anotherNums.begin(), anotherNums.end());
        if(nums == anotherNums)
            puts("Yes");
        else 
            puts("No");
        cout << ans[ans.size() - 1];
        for(int i = ans.size() - 2; i >= 0; --i)
            cout << " " << ans[i];
        cout << "\n";
    }
    return 0;
}