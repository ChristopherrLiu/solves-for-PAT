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
#define maxn 40
#define maxe 1048586
using namespace std;

struct Node {
    char c;
    int num;
    bool isWord;
    Node* son[maxn];
    Node(char c_) {
        c = c_;
        isWord = false;
        num = 0;
        for(int i = 0; i < maxn; ++i)
            son[i] = nullptr;
    }
};

int ans, c;
char ansWord[maxn];
Node* root;

bool check(char c) {
    return (c >= 'A' && c < 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

void insert(char *word) {
    int Len = strlen(word);
    Node* cur = root;
    for(int i = 0; i < Len; ++i) {
        int id = word[i] - 'a' + 10;
        if(word[i] >= '0' && word[i] <= '9')
            id = word[i] - '0';
        if(cur->son[id] == nullptr) {
            cur->son[id] = new Node(word[i]);
        }
        cur = cur->son[id];
    }
    cur->isWord = true;
    cur->num++;
    if(cur->num > ans) {
        ans = cur->num;
        strcpy(ansWord, word);
    }
}

int main() {
    root = new Node(0);
    char curWord[maxn];
    int cnt = 0;
    c = getchar();
    while(c != '\n') {
        if(check(c)) {
            if(c >= 'A' && c <= 'Z') {
                curWord[cnt++] = c + 32;
            }
            else {
                curWord[cnt++] = c;
            }   
        }
        else {
            if(cnt) {
                curWord[cnt] = 0;
                insert(curWord);
                cnt = 0;
            }
        }
        c = getchar();
    }
    if(cnt) {
        curWord[cnt] = 0;
        insert(curWord);
        cnt = 0;
    }
    printf("%s %d\n", ansWord, ans);
    getchar();
    getchar();
    return 0;
}