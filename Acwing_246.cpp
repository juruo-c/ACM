//https://www.acwing.com/problem/content/247/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 500005;

int n, m;
LL a[N], b[N], c[N];
struct Tree
{
    int l, r;
    LL g;
}t[N << 2];

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

void push_up(int i)
{
    t[i].g = gcd(t[i << 1].g, t[i << 1 | 1].g);
}

void build(int i, int l, int r)
{
    t[i] = {l, r, 0};
    if (l == r)
    {
        t[i].g = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void update(int i, int pos, LL k)
{
    if (t[i].l == t[i].r)
    {
        t[i].g += k;
        return;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (pos <= mid) update(i << 1, pos, k);
    else update(i << 1 | 1, pos, k);
    push_up(i);
}

LL query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
        return t[i].g;
    int mid = t[i].l + t[i].r >> 1;
    if (l > mid) return query(i << 1 | 1, l, r);
    else if (r <= mid) return query(i << 1, l, r);
    else return gcd(query(i << 1, l, r), query(i << 1 | 1, l, r));
}

void add(int x, LL k)
{
    for (int i = x; i <= n; i += (i & -i))
        c[i] += k;
}

LL ask(int x)
{
    LL ans = 0;
    for (int i = x; i; i -= (i & -i))
        ans += c[i];
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%lld", &a[i]);
        b[i] = a[i] - a[i - 1];
        add(i, b[i]);
    }
    build(1, 1, n + 1);

    for (int i = 1; i <= m; i ++ )
    {
        char op;
        int l, r;
        LL d;
        scanf("\n%c%d%d", &op, &l, &r);

        if (op == 'C')
        {
            scanf("%lld", &d);
            update(1, l, d);
            update(1, r + 1, -d);
            add(l, d);
            add(r + 1, -d);
        }
        else
        {
            if (l < r)
               printf("%lld\n", abs(gcd(ask(l), query(1, l + 1, r))));
            else if (l == r)
                printf("%lld\n", ask(l));
        }
    }
    return 0;
}
