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
#define maxn 2010
#define maxe 110
using namespace std;

int n;
char nums[maxe];

int main() {
    while(~scanf("%d", &n)) {
        double ans = 0;
        int legalNum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%s", nums);
            int len = strlen(nums);
            bool isLegal = true, dotFlag = false;
            double num = 0, bas = 0.1, opt = 1;
            for(int i = 0; i< len; ++i) {  
                if(nums[i] == '-') {
                    if(i != 0) {
                        isLegal = false;
                        break;
                    }
                    else {
                        opt = -1;
                    }
                } 
                else if(nums[i] == '.') {
                    if(dotFlag) {
                        isLegal = false;
                        break;
                    }
                    else {
                        dotFlag = true;
                        continue;
                    }
                }
                else if(nums[i] >= '0' && nums[i] <= '9') {
                    if(!dotFlag) {
                        num = num * 10 + nums[i] - '0';
                    }
                    else {
                        if(bas < 0.01) {
                            isLegal = false;
                            break;
                        }
                        num = num + (nums[i] - '0') * bas;
                        bas *= 0.1;
                    }
                }
                else {
                    isLegal = false;
                    break;
                }
            }
            num *= opt;
            if(num > 1000 || num < -1000)
                isLegal = false;
            if(isLegal) {
                ans += num;
                legalNum++;
            }
            else {
                printf("ERROR: %s is not a legal number\n", nums);
            }
        }
        if(legalNum == 0) {
            printf("The average of 0 numbers is Undefined\n");
        }
        else if(legalNum == 1) {
            printf("The average of 1 number is %.2f\n", ans);
        }
        else {
            printf("The average of %d numbers is %.2f\n", legalNum, ans / legalNum);
        }
    }
    return 0;
}