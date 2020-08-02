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
#define maxe 10
using namespace std;

int n, k;
char opt[maxe];
int num[maxn], blockNum[320];
int stack[maxn], top, tail;

void getKTop(int l, int r, int id);

void init() {
    top = 0;
    tail = 1;
}

void push(int key) {
    stack[++top] = key;
    num[key]++;
    blockNum[key / 316]++;
}

void pop() {
    if(top < tail)
        puts("Invalid");
    else {
        num[stack[top]]--;
        blockNum[stack[top] / 316]--;
        printf("%d\n", stack[top]);
        --top;
    }
}

void peekMedian() {
    if(top < tail)
        puts("Invalid");
    else {
        int id = (int)ceil(top * 1.0 / 2);
        int cur = 0, bid = 0;
        while(cur < id) {
            cur += blockNum[bid];
            ++bid;
        }
        cur -= blockNum[bid - 1];
        for(int i = (bid - 1) * 316; i < bid * 316; ++i) {
            cur += num[i];
            if(cur >= id) {
                printf("%d\n", i);
                break;
            }
        }
        // memcpy(temp, stack, sizeof(stack));
        // getKTop(tail, top, id);
        // printf("%d\n", stack[(int)ceil(top * 1.0 / 2)]);
    }
}

// void getKTop(int l, int r, int id) {
//     if(l == r) {
//         // printf("#### %d\n", l);
//         printf("%d\n", temp[l]);
//         return;
//     }
//     int tag = temp[l];
//     int pl = l, pr = r;
//     while(pl < pr) {
//         while(pl < pr && temp[pr] >= tag)
//             --pr;
//         if(pl < pr)
//             temp[pl] = temp[pr];
//         while(pl < pr && temp[pl] <= tag)
//             ++pl;
//         if(pl < pr)
//             temp[pr] = temp[pl];
//     }
//     temp[pl] = tag;
//     // printf("#### %d %d %d %d\n", pl, l, r, id);
//     if(pl - l >= id)
//         getKTop(l, pl - 1, id);
//     else if(pl - l + 1 < id)
//         getKTop(pl + 1, r, id - (pl - l + 1));
//     else
//         printf("%d\n", temp[pl]);
// }

int main() {
    init();
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            getchar();
            scanf("%s", opt);
            if(strcmp(opt, "Push") == 0) {
                scanf("%d", &k);
                push(k);
            }
            else if(strcmp(opt, "Pop") == 0) {
                pop();
            }
            else {
                peekMedian();
            }
        }
    }
    return 0;
}