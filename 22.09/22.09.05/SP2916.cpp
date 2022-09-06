#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;   

LL a[N];
struct Tree
{
    int l, r;
    LL sum;
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

void update(int i, int l, int r)
{
    if (t[i].sum <= t[i].r - t[i].l + 1) return;
    if (t[i].l == t[i].r)
    {
        t[i].sum = sqrt(t[i].sum);
        return;
    }
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) update(i << 1, l, r);
    if (r > mid) update(i << 1 | 1, l, r);
    push_up(i);
}

LL query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
        return t[i].sum;
    int mid = (t[i].l + t[i].r) >> 1;
    if (l > mid) return query(i << 1 | 1, l, r);
    else if(r <= mid) return query(i << 1, l, r);
    else return query(i << 1, l, r) + query(i << 1 | 1, l, r);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int kase = 0;
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i ++ )
            scanf("%lld", &a[i]);
        build(1, 1, n);
        int m;
        printf("Case #%d:\n", ++ kase);
        scanf("%d", &m);
        for (int i = 1; i <= m; i ++ )
        {
            int op, l, r;
            scanf("%d%d%d", &op, &l, &r);
            if (l > r) swap(l, r);
            if (op == 0) update(1, l, r);
            else printf("%lld\n", query(1, l, r));
        }
        puts("");
    }
    return 0;
}