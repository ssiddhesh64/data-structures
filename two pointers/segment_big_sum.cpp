#include <bits/stdc++.h>
// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D
// Given an array of 𝑛 integers 𝑎𝑖. Let's say that the segment of this array 𝑎[𝑙..𝑟] (1≤𝑙≤𝑟≤𝑛) is good if the sum of elements on this segment is at least 𝑠. Your task is to find the number of good segments.
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
    // ll ans = INT_MAX;
    ll ans = 0;
    
    for(int r = 0; r < n; r++){
        cur_sum += a[r];
        while(cur_sum - a[l] >= sum){
            cur_sum -= a[l];
            l++;
        }
        // l .. r is good segment
        // ans += r - l + 1;
        if(cur_sum >= sum){
            ans += l + 1; 
        }
    }
    // if(ans == INT_MAX) cout << "-1\n";
    // else cout << ans << endl;

    cout << ans << endl;
    
}