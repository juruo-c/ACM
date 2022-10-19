#include <iostream>

using namespace std;

const int N = 100005;

int n, m, p;
int a[N];
struct Tree
{
    int l, r;
    int sum;
    int add, mul;
}t[N << 2];

void push_up(int i)
{
    t[i].sum = (t[i << 1].sum + t[i << 1 | 1].sum) % p;
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    t[i].mul = 1;
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

void calc(int i, int mul, int add)
{
    t[i].add = (1LL * t[i].add * mul % p + add) % p;
    t[i].mul = 1LL * mul * t[i].mul % p;
    t[i].sum = (1LL * t[i].sum * mul % p + 1LL * add * (t[i].r - t[i].l + 1) % p) % p;
}

void push_down(int i)
{
    calc(i << 1, t[i].mul, t[i].add);
    calc(i << 1 | 1, t[i].mul, t[i].add);
    t[i].mul = 1, t[i].add = 0;
}

void updateAdd(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r) 
    {
        t[i].add = (t[i].add + k) % p;
        t[i].sum = (t[i].sum + 1LL * k * (t[i].r - t[i].l + 1) % p) % p;
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) updateAdd(i << 1, l, r, k);
    if (r > mid) updateAdd(i << 1 | 1, l, r, k);
    push_up(i);
}

void updateMul(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        t[i].add = 1LL * t[i].add * k % p;
        t[i].mul = 1LL * t[i].mul * k % p;
        t[i].sum = 1LL * t[i].sum * k % p;
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) updateMul(i << 1, l, r, k);
    if (r > mid) updateMul(i << 1 | 1, l, r, k);
    push_up(i);
}

int query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
        return t[i].sum;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    int s = 0;
    if (l <= mid) s = (s + query(i << 1, l, r)) % p;
    if (r > mid) s = (s + query(i << 1 | 1, l, r)) % p;
    return s;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);

    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    
    build(1, 1, n);

    for (int i = 1; i <= m; i ++ )
    {
        int op;
        int l, r, k;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1 || op == 2)
        {
            scanf("%d", &k);
            if (op == 1) updateMul(1, l, r, k);
            else updateAdd(1, l, r, k);
        }
        else printf("%d\n", query(1, l, r));
    }

    return 0;
}