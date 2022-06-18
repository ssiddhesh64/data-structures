#include <bits/stdc++.h>

using namespace std;
vector<int> arr;

struct entity
{
    long long count;
    long long val;
};
vector<entity> tree;

// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

int build(int node, int l, int r)
{
    // range contains segment case
    // this case it is a leaf
    if (l == r)
    {
        tree[node].val = arr[l];
        tree[node].count = 1;
        return 0;
    }

    int mid = (l + r) / 2;

    // builf left
    build(2 * node + 1, l, mid);
    // build right
    build(2 * node + 2, mid + 1, r);

    // update current node
    // tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    if (tree[2 * node + 1].val == tree[2 * node + 2].val)
    {
        tree[node].val = tree[2 * node + 1].val;
        tree[node].count = tree[2 * node + 1].count + tree[2 * node + 2].count;
    }
    else if (tree[2 * node + 1].val < tree[2 * node + 2].val)
    {
        tree[node].val = tree[2 * node + 1].val;
        tree[node].count = tree[2 * node + 1].count;
    }
    else
    {
        tree[node].val = tree[2 * node + 2].val;
        tree[node].count = tree[2 * node + 2].count;
    }

    return 0;
}

pair<long long, long long> query(int node, int sl, int sr, int ql, int qr)
{
    if (qr >= sr and ql <= sl)
        return make_pair(tree[node].val, tree[node].count);

    if (qr < sl or ql > sr)
        return make_pair(1e9, 1e9);

    int mid = (sl + sr) / 2;
    // return query(2 * node + 1, sl, mid, ql, qr) + query(2 * node + 2, mid + 1, sr, ql, qr);

    pair<long long, long long> val1 = query(2 * node + 1, sl, mid, ql, qr);
    pair<long long, long long> val2 = query(2 * node + 2, mid + 1, sr, ql, qr);
    if (val1.first == val2.first)
        return make_pair(val1.first, val1.second + val2.second);
    else if (val1.first < val2.first)
        return make_pair(val1.first, val1.second);
    else
        return make_pair(val2.first, val2.second);
}

int update(int node, int l, int r, int val, int ind)
{
    if (l == r)
    {
        tree[node].val = val;
        tree[node].count = 1;
        return 0;
    }

    int mid = (l + r) / 2;

    if (ind <= mid)
        update(2 * node + 1, l, mid, val, ind);
    else
        update(2 * node + 2, mid + 1, r, val, ind);

    // update current node
    // tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    if (tree[2 * node + 1].val == tree[2 * node + 2].val)
    {
        tree[node].val = tree[2 * node + 1].val;
        tree[node].count = tree[2 * node + 1].count + tree[2 * node + 2].count;
    }
    else if (tree[2 * node + 1].val < tree[2 * node + 2].val)
    {
        tree[node].val = tree[2 * node + 1].val;
        tree[node].count = tree[2 * node + 1].count;
    }
    else
    {
        tree[node].val = tree[2 * node + 2].val;
        tree[node].count = tree[2 * node + 2].count;
    }
    return 0;
}

unsigned int nextPowerOf2(unsigned int n)
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

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    n = nextPowerOf2(n);
    arr.resize(n, 1e9);
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    //     /* code */
    // }

    tree.resize(2 * n);
    for (size_t i = 0; i < 2 * n; i++)
    {
        tree[i].val = 1e9;
        /* code */
    }

    build(0, 0, n - 1);

    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1)
            update(0, 0, n - 1, r, l);
        else
        {
            pair<long long, long long> ans = query(0, 0, n - 1, l, r - 1);
            cout << ans.first << " " << ans.second << endl;
        }
    }

    return 0;
}