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
#define maxe 10
using namespace std;

int main(){
	int n;
	cin >> n;
	int m = sqrt((double)n);
	int maxCount = 0;
	int first = n;
	for(int i = 2;i <= m; i++){
		int count = 0;
		int start = i;
		int tmp = n;
		while(tmp%start == 0){
			count++;
			tmp = tmp / start;
			start++;
		}
		if(start - i > maxCount){
			maxCount = start-i;
			first = i;
		}
	}
	if(maxCount == 0){
		cout << 1 << endl;
		cout << n;
		return 0;
	}
	cout << maxCount << endl;
	cout << first;
	for(int i = 1; i < maxCount; i++)
		cout << "*" << first + i;
	return 0;
}