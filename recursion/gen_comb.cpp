#include<bits/stdc++.h>

using namespace std;

void generate(int i, string cur, int n, vector<string>& ans) {
    // cout << cur << endl;
    if(i == n) {
        ans.push_back(cur);
        return;
    }

    for(int j = i; j < n; j++) {
        if(i == j || cur[i] != cur[j]) {
            swap(cur[i], cur[j]);
            generate(i + 1, cur, n, ans);
            swap(cur[i], cur[j]);
        }
    }
}

int main() {

    string s = "aabc";
    vector<string> comb;
    // comb.push_back(s);
    generate(0, s, s.size(), comb);
    for(string str : comb) {
        cout << str << " ";
    }
    return 0;
}