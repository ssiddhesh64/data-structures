#include <bits/stdc++.h>
// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
using namespace std;

typedef long long ll;
int main() {

    int n;
    ll sum;
    cin >> n >> sum;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 0;
    ll cur_sum = 0;
    int ans = INT_MAX;
    
    for(int r = 0; r < n; r++){
        cur_sum += a[r];
        while(cur_sum - a[l] >= sum){
            cur_sum -= a[l];
            l++;
        }
        if(cur_sum >= sum) ans = min(ans, r - l + 1);
    }
    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans << endl;
    
}