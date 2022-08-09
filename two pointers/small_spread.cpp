#include<bits/stdc++.h>
// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
using namespace std;
typedef long long ll;

ll min(ll n1, ll n2){
    return n1 < n2 ? n1 : n2;
}

ll max(ll n1, ll n2){
    return n1 > n2 ? n1 : n2;
}
struct st{

    vector<ll> s1, smin, smax;

    st(){
        smin.push_back(LLONG_MAX);
        smax.push_back(LLONG_MIN);
    }

    void push(ll x){
        s1.push_back(x);
        smin.push_back(::min(smin.back(), x));
        smax.push_back(::max(smax.back(), x));
    }

    ll pop(){
        ll res = s1.back();
        s1.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }

    bool empty(){
        return s1.empty();
    }

    ll max(){
        assert(smax.size() != 0);
        return smax.back();
    }

    ll min(){
        assert(smin.size() != 0);
        return smin.back();
    }

};

void add(st &s, ll x){
    s.push(x);
}

void remove(st &s1, st &s2){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good(st &s1, st &s2, ll k){
    ll mn = min(s1.min(), s2.min());
    ll mx = max(s1.max(), s2.max());
    return mx - mn <= k;
}

int main(){

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    st s1, s2;
    ll l = 0, r = 0;
    ll ans = 0;
    for (size_t r = 0; r < n; r++) {
        add(s2, arr[r]);
        while(!good(s1, s2, k)){
            remove(s1, s2);
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}