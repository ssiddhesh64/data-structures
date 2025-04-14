#include<bits/stdc++.h>

using namespace std;

void sieve(vector<int>& primes, int upto) {

    vector<int> sieve(upto + 1, true);
    for(int i = 2; i <= upto; i++) {
        if(!sieve[i]) continue;
        primes.push_back(i);
        for (int j = i*i; j <= upto; j+=i) {
            sieve[j] = false;
        }
    }
}

int main() {

    vector<int> primes;
    int upto = 1e4;
    sieve(primes, upto);

    for(auto p: primes) cout << p << " ";
    cout << endl;
}