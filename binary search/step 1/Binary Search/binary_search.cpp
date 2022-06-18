#include <bits/stdc++.h>

using namespace std;

string query(vector<int> &arr, int val, int l, int r)
{
    if (l > r)
    {
        return "NO";
        // single element
        // if (arr[mid] == val)
        //     return "YES";
        // else
        //     return "NO";
    }
    int mid = (l + r) / 2;
    if (arr[mid] == val)
        return "YES";
    if (val < arr[mid])
        return query(arr, val, l, mid - 1);
    return query(arr, val, mid + 1, r);
}

string query(vector<int> &arr, int val, int n)
{
    return query(arr, val, 0, n - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++)
        cin >> arr[i];

    while (k--)
    {
        int val;
        cin >> val;
        cout << query(arr, val, n) << endl;
    }
    return 0;
}