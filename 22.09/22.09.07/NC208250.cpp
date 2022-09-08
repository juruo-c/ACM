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

const int N = 1000005, INF = 0x3f3f3f3f;

int n;
int a[N];
struct TreeNode
{
    int l, r;
    int sum, mi, mx;
}t[N << 2];

void push_up(int i)
{
    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
    t[i].mi = min(t[i << 1].mi, t[i << 1 | 1].mi);
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r)
    {
        t[i].mi = t[i].mx = a[l];
        t[i].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void update(int i, int k)
{
    if (t[i].l == t[i].r)
    {
        t[i].sum = 0;
        t[i].mi = INF;
        t[i].mx = -INF;
        return;
    }
    if (t[i << 1].sum >= k) update(i << 1, k);
    else update(i << 1 | 1, k - t[i << 1].sum);
    push_up(i);
}

int queryMx(int i, int l, int r)
{
    if (l <= 1 && t[i].sum <= r) return t[i].mx;
    int mx = -INF;
    if (l <= t[i << 1].sum) mx = max(queryMx(i << 1, l, r), mx);
    if (r > t[i << 1].sum) mx = max(mx, queryMx(i << 1 | 1, l - t[i << 1].sum, r - t[i << 1].sum));
    return mx;
}

int queryMi(int i, int l, int r)
{
    if (l <= 1 && t[i].sum <= r) return t[i].mi;
    int mi = INF;
    if (l <= t[i << 1].sum) mi = min(queryMi(i << 1, l, r), mi);
    if (r > t[i << 1].sum) mi = min(mi, queryMi(i << 1 | 1, l - t[i << 1].sum, r - t[i << 1].sum));
    return mi;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    build(1, 1, n);

    for (int i = 1; i <= m; i ++ )
    {
        int op, l, r;
        scanf("%d", &op);
        if (op == 1)
        {
            int x;
            scanf("%d", &x);
            update(1, x);
        }
        else 
        {
            scanf("%d%d", &l, &r);
            printf("%d %d\n", queryMi(1, l, r), queryMx(1, l, r));
        }
    }
    
    return 0;
}
