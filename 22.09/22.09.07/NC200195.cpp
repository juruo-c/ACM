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

const int N = 200005;

int n, m;
int a[N];
struct TreeNode
{
    int l, r;
    LL sum, lz;
}t[N << 2];

void push_up(int i)
{
    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r)
    {
        t[i].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void Add(int i, LL lz, int l)
{
    t[i].lz = t[i].l - l + lz;
    t[i].sum = (2 * lz + t[i].r - t[i].l) * (t[i].r - t[i].l + 1) / 2;
}

void push_down(int i)
{
    if (t[i].lz)
    {
        Add(i << 1, t[i].lz, t[i].l);
        Add(i << 1 | 1, t[i].lz, t[i].l);
        t[i].lz = 0;
    }
}   

void update(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        Add(i, k, l);
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) update(i << 1, l, r, k);
    if (r > mid) update(i << 1 | 1, l, r, k);
    push_up(i);
}

LL query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].sum;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    LL s = 0;
    if (l <= mid) s += query(i << 1, l, r);
    if (r > mid) s += query(i << 1 | 1, l, r);
    return s;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    build(1, 1, n);

    for (int i = 1; i <= m; i ++ )
    {
        int op, l, r, k;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            scanf("%d", &k);
            update(1, l, r, k);
        }
        else 
        {
            printf("%lld\n", query(1, l, r));
            // cout << "over" << endl;
        }
    }
    return 0;
}
