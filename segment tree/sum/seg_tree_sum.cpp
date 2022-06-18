#include <bits/stdc++.h>

using namespace std;

vector<long long> tree;
vector<long long> arr;

int build(int node, int left, int right)
{
    // cout << node << "int node" << endl;

    if (left == right)
    {
        // cout << "leaf " << left << endl;
        tree[node] = arr[left];
        return 0;
    }

    long long mid = (left + right) / 2;
    build(2 * node + 1, left, mid);
    build(2 * node + 2, mid + 1, right);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    return 0;
}

long long query(int node, int sl, int sr, int ql, int qr)
{

    if (ql <= sl and qr >= sr)
        return tree[node];
    if (ql > sr or qr < sl)
        return 0;

    long long mid = (sl + sr) / 2;
    return query(2 * node + 1, sl, mid, ql, qr) + query(2 * node + 2, mid + 1, sr, ql, qr);
}

int update(int node, int ind, int sl, int sr, int val)
{
    if (sl == sr)
    {
        tree[node] = val;
        return 0;
    }

    long long mid = (sl + sr) / 2;
    if (ind <= mid)
        update(2 * node + 1, ind, sl, mid, val);
    else
        update(2 * node + 2, ind, mid + 1, sr, val);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    return 0;
}

unsigned int nextPowerof2(unsigned int n)
{
    unsigned int p = 1;

    if (n && !(n & (n - 1)))
        return n;

    while (p < n)
        p <<= 1;

    return p;
}

int main()
{
    int n, m;
    cin >> n >> m;
    arr.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i];
        /* code */
    }
    // cout << endl;
    n = nextPowerof2(n);
    // cout << n << endl;
    arr.resize(n);
    tree.resize(2 * n);
    build(0, 0, n - 1);

    // cout << "print tree" << endl;
    // for (size_t i = 0; i < 2 * n; i++)
    // {
    //     cout << tree[i] << " ";
    //     /* code */
    // }
    // cout << "print tree end" << endl;

    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1)
        {
            update(0, l, 0, n - 1, r);
        }
        else
        {
            cout << query(0, 0, n - 1, l, r - 1) << endl;
        }
        /* code */
    }
}