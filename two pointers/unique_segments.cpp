#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
int main(){

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = 0;
    unordered_map<int, int> c;
    // set<int> s;
    int unq = 0;
    ll ans = 0;
    for (size_t r = 0; r < n; r++) {
        // s.insert(arr[r]);

        if(c[arr[r]] == 0) unq++;
        c[arr[r]]++;
        // cout << arr[r] << " " << c[arr[r]] << " " << unq << endl;

        while(unq > k){
            if(c[arr[l]] == 1){
                // s.erase(arr[r]);
                c[arr[l]] = 0;;
                unq--;
            } else c[arr[l]]--;
            l++;
        }
        ans += r - l + 1;
    }
    
    cout << ans << endl;
    return 0;
}