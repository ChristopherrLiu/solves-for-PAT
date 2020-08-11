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
#define maxn 200010
#define maxe 2
using namespace std;

int N;
int a[maxn];

int main() {
	while(~scanf("%d", &N)) {
        for (int i = 0; i < N; i++) {
		    scanf("%d", &a[i]);
	    }
	    sort(a, a + N);
	    int sum1 = 0, sum2 = 0;
	    for(int i = 0; i < N; i++){
		    if (i <= N / 2 - 1)
			    sum1 += a[i];
		    else
			    sum2 += a[i];
	    }
	    if (N % 2 == 0)
		    printf("%d %d\n", 0, sum2 - sum1);
	    else
		    printf("%d %d\n", 1, sum2 - sum1);
    }
	return 0;
}