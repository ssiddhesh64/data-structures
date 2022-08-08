#include <bits/stdc++.h>
// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    // vector<int> res(n + m, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int left = 0, right = 0;
    long long ls = 1; long long rs = 1;
    long long ans = 0;
    int i = 0;
    while (left < n and right < m) {
        if (a[left] < b[right]){
            ls = 1;
            // res[i] = a[left];
            left++;
        }
        else if(a[left] > b[right]) {
            rs = 1;
            // cout << left << " ";
            // res[i] = b[right];
            right++;
        } else {
            while(left + 1 < n and a[left + 1] == b[right]){
                ls++;
                left++;
            }
            while(right + 1 < m and a[left] == b[right + 1]){
                rs++;
                right++;
            }   
            ans += ls * rs;
            ls = 1;
            rs = 0;
            left++;
        }
        i++;
    }
    // while (left < n){
    //     res[i] = a[left];
    //     left++;
    //     i++;
    // }
    // while (right < m){
    //     // cout << n << " ";
    //     res[i] = b[right];
    //     right++;
    //     i++;
    // }
    cout << ans << endl;
    // for (int i = 0; i < n + m; i++){
    //     cout << res[i] << " ";
    // }
}