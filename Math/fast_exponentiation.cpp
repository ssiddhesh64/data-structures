#include<bits/stdc++.h>

using namespace std;

long long power(long long base, long long exponent, long long mod) {

    long long res = 1;

    while(exponent) {
        if(exponent&1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return res;
}

int main() {

    cout << power(2, 10, 1e5);
}