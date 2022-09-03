//https://www.acwing.com/problem/content/244/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
struct Tree
{
    int l, r;
    LL w, lz;
}t[N << 2];
int a[N];

void push_up(int i)
{
    t[i].w = t[i << 1].w + t[i << 1 | 1].w;
}

void push_down(int i)
{
    if (t[i].lz)
    {
        t[i << 1].lz += t[i].lz;
        t[i << 1 | 1].lz += t[i].lz;
        t[i << 1].w += t[i].lz * (t[i << 1].r - t[i << 1].l + 1);
        t[i << 1 | 1].w += t[i].lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1);
        t[i].lz = 0;
    }
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r)
    {
        t[i].w = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void update(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        t[i].lz += k;
        t[i].w += k * (t[i].r - t[i].l + 1);
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
    if (l <= t[i].l && t[i].r <= r)
        return t[i].w;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    LL s = 0;
    if (l <= mid) s += query(i << 1, l, r);
    if (r > mid) s += query(i << 1 | 1, l, r);
    return s;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);

    build(1, 1, n);
    for (int i = 1; i <= m; i ++ )
    {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'C')
        {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            update(1, l, r, d);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }

    return 0;
}
