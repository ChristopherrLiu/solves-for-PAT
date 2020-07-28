#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxe = 2020;

struct Polynomials {
    int nozeroTerms;
    double coefficients[maxe];
    void print() {
        printf("%d", this->nozeroTerms);
        for(int i = 2000; i >= 0; --i) {
            if(this->coefficients[i] == 0)
                continue;
            printf(" %d %.1f", i, this->coefficients[i]);
        }
        printf("\n");
    }
    void init() {
        memset(this->coefficients, 0, sizeof(this->coefficients));
        nozeroTerms = 0;
    }
    void setTerm(int exp, double coef) {
        if(coef == 0)
            return;
        if(!this->coefficients[exp])
            this->nozeroTerms++;
        this->coefficients[exp] = coef;
    }
    void updateTerm(int exp, double coef) {
        if(coef == 0)
            return;
        if(!this->coefficients[exp])
            this->nozeroTerms++;
        this->coefficients[exp] += coef;
        if(this->coefficients[exp] == 0)
            this->nozeroTerms--;
    }
    Polynomials operator+ (const Polynomials &other) {
        Polynomials res;
        res.init();
        for(int i = 0; i <= 1000; ++i) {
            res.setTerm(i, this->coefficients[i] + other.coefficients[i]);
        }
        return res;
    }
    Polynomials operator* (const Polynomials &other) {
        Polynomials res;
        res.init();
        for(int i = 0; i <= 1000; ++i) {
            for(int j = 0; j <= 1000; ++j) {
                res.updateTerm(i + j, this->coefficients[i] * other.coefficients[j]);
            }
        }
        return res;
    }
}a, b, c;

int k, e;
double coef;

int main() {
    while(~scanf("%d", &k)) {
        a.init();
        b.init();
        for(int i = 0; i < k; ++i) {
            scanf("%d %lf", &e, &coef);
            a.setTerm(e, coef);
        }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d %lf", &e, &coef);
            b.setTerm(e, coef);
        }
        c = a * b;
        c.print();
    }
    return 0;
}