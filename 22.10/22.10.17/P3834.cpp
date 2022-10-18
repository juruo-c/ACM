#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n, m;
int rt[N];
int a[N], b[N];
struct tree
{
    int l, r;
    int sum;
}t[N * 50];
int cnt;

void build(int& i, int l, int r)
{
    if (!i) i = ++ cnt;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(t[i].l, l, mid);
    build(t[i].r, mid + 1, r);
}

int update(int i, int l, int r, int pos)
{
    int p = ++ cnt;
    t[p] = t[i];
    t[p].sum ++;
    if (l == r)
        return p;
    int mid = (l + r) >> 1;
    if (pos <= mid) t[p].l = update(t[p].l, l, mid, pos);
    else t[p].r = update(t[p].r, mid + 1, r, pos);
    return p;
}

int query(int u, int v, int l, int r, int k)
{
    if (l == r) return l;
    int x = t[t[v].l].sum - t[t[u].l].sum;
    int mid = (l + r) >> 1;
    if (x >= k) return query(t[u].l, t[v].l, l, mid, k);
    else return query(t[u].r, t[v].r, mid + 1, r, k - x);
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]), b[i] = a[i];
    
    sort(b + 1, b + 1 + n);
    int len = unique(b + 1, b + 1 + n) - b - 1;
    build(rt[0], 1, len);

    for (int i = 1; i <= n; i ++ )
        rt[i] = update(rt[i - 1], 1, len, lower_bound(b + 1, b + 1 + len, a[i]) - b);

    for (int i = 1; i <= m; i ++ )
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", b[query(rt[l - 1], rt[r], 1, len, k)]);
    }

    return 0;
}
