#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 50005;

int a[N];
struct TreeNode
{
    int l, r;
    int sum, lmx, rmx, mx;
}t[N << 2];

TreeNode push_up(TreeNode& a, TreeNode& b)
{
    TreeNode res;
    res.l = a.l, res.r = b.r;
    res.sum = a.sum + b.sum;
    res.mx = max(max(a.mx, b.mx), a.rmx + b.lmx);
    res.lmx = max(a.lmx, a.sum + b.lmx);
    res.rmx = max(b.rmx, b.sum + a.rmx);
    return res;
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r)
    {
        t[i].sum = t[i].lmx = t[i].rmx = t[i].mx = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    t[i] = push_up(t[i << 1], t[i << 1 | 1]);
}

TreeNode query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
        return t[i];
    int mid = (t[i].l + t[i].r) >> 1;
    if (l > mid) return query(i << 1 | 1, l, r);
    else if(r <= mid) return query(i << 1, l, r);
    else
    {
        TreeNode a = query(i << 1, l, r), b = query(i << 1 | 1, l, r);
        return push_up(a, b);
    }
}

void update(int i, int pos, int k)
{
    if (t[i].l == t[i].r)
    {
        t[i].sum = t[i].lmx = t[i].rmx = t[i].mx = k;
        return;
    }
    int mid = (t[i].l + t[i].r) >> 1;
    if (pos <= mid) update(i << 1, pos, k);
    else update(i << 1 | 1, pos, k);
    t[i] = push_up(t[i << 1], t[i << 1 | 1]);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    build(1, 1, n);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ )
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op)
            printf("%d\n", query(1, l, r).mx);
        else update(1, l, r);
    }
    return 0;
}
