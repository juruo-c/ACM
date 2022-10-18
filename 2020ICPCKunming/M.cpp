#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1000005, INF = 1e9;

int n, q;
int a[N];
int rt[N];
struct Tree
{
    int l, r;
    LL sum;
}t[N * 50];
int cnt;

int update(int i, int l, int r, int pos)
{
    int p = ++ cnt;
    t[p] = t[i];
    t[p].sum += pos;
    if (l == r) 
        return p;
    int mid = (l + r) >> 1;
    if (pos <= mid) t[p].l = update(t[i].l, l, mid, pos);
    else t[p].r = update(t[i].r, mid + 1, r, pos);
    return p;
}   

LL query(int L_rt, int R_rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return t[R_rt].sum - t[L_rt].sum;
    int mid = (l + r) >> 1;
    LL s = 0;
    if (L <= mid) s += query(t[L_rt].l, t[R_rt].l, l, mid, L, R);
    if (R > mid) s += query(t[L_rt].r, t[R_rt].r, mid + 1, r, L, R);
    return s; 
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ )
        rt[i] = update(rt[i - 1], 1, INF, a[i]);

    LL last = 0;
    for (int i = 1; i <= q; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if (l > r) swap(l, r);
        LL x = 0;
        while (true)
        {
            LL t = query(rt[l - 1], rt[r], 1, INF, 1, min(1LL * INF, x + 1));
            if (t == x) break;
            x = t;
        }
        printf("%lld\n", x + 1);
        last = x + 1;
    }

    return 0;
}