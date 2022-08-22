//https://www.acwing.com/problem/content/246/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 500005, INF = 0x3f3f3f3f;

int n, m;
int a[N];
struct Tree
{
    int l, r;
    int sum, mx;
    int lmx, rmx;
}t[N << 2];

void push_up(int i)
{
    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].lmx = max(t[i << 1].lmx, t[i << 1 | 1].lmx + t[i << 1].sum);
    t[i].rmx = max(t[i << 1 | 1].rmx, t[i << 1 | 1].sum + t[i << 1].rmx);
    t[i].mx = max(t[i].mx, t[i << 1].rmx + t[i << 1 | 1].lmx);
}

void build(int i, int l, int r)
{
    t[i] = {l, r, 0, 0, 0, 0};
    if (l == r)
    {
        t[i].sum = t[i].mx = t[i].lmx = t[i].rmx = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void update(int i, int pos, int k)
{
    if (t[i].l == t[i].r)
    {
        t[i].sum = t[i].mx = t[i].lmx = t[i].rmx = k;
        return;
    }
    int mid = (t[i].l + t[i].r) >> 1;
    if (pos <= mid) update(i << 1, pos, k);
    else update(i << 1 | 1, pos, k);
    push_up(i);
}

Tree query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i];
    int mid = t[i].l + t[i].r >> 1;

    if (l > mid) return query(i << 1 | 1, l, r);
    else if (r <= mid) return query(i << 1, l, r);
    else
    {
        Tree t1 = query(i << 1, l, r), t2 = query(i << 1 | 1, l, r), t3;
        t3.l = l, t3.r = r;
        t3.sum = t1.sum + t2.sum;
        t3.mx = max(t1.mx, t2.mx);
        t3.lmx = max(t1.lmx, t1.sum + t2.lmx);
        t3.rmx = max(t2.rmx, t2.sum + t1.rmx);
        t3.mx = max(t3.mx, t1.rmx + t2.lmx);
        return t3;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    build (1, 1, n);

    for (int i = 1; i <= m; i ++ )
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            if (x > y) swap(x, y);
            printf("%d\n", query(1, x, y).mx);
        }
        else
            update(1, x, y);
    }

    return 0;
}
