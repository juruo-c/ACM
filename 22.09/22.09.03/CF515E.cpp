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

int d[N * 2], h[N * 2];
LL s1[N * 2], s2[N * 2];

struct Tree
{
    int l, r;
    int mxp, mip;
}t[N << 4];

int calcMx(int i, int j)
{
    return s1[i] > s1[j] ? i : j;
}

int calcMi(int i, int j)
{
    return s2[i] < s2[j] ? i : j;
}

void push_up(int i)
{
    t[i].mip = calcMi(t[i << 1].mip, t[i << 1 | 1].mip);
    t[i].mxp = calcMx(t[i << 1].mxp, t[i << 1 | 1].mxp);
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r)
    {
        t[i].mxp = t[i].mip = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

int queryMi(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].mip;
    int mid = (t[i].l + t[i].r) >> 1;

    if (l > mid) return queryMi(i << 1 | 1, l, r);
    else if(r <= mid) return queryMi(i << 1, l, r);
    else return calcMi(queryMi(i << 1, l, r), queryMi(i << 1 | 1, l, r));
}

int queryMx(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].mxp;
    int mid = (t[i].l + t[i].r) >> 1;

    if (l > mid) return queryMx(i << 1 | 1, l, r);
    else if(r <= mid) return queryMx(i << 1, l, r);
    else return calcMx(queryMx(i << 1, l, r), queryMx(i << 1 | 1, l, r));
}

int getMx(int l, int r)
{
    if (l > r) return 0;
    return queryMx(1, l, r);
}

int getMi(int l, int r)
{
    if (l > r) return 0;
    return queryMi(1, l, r);
}

LL solve(int l, int r)
{
    int mxp = getMx(l, r), mip = getMi(l, r);
    if (mip != mxp) return s1[mxp] - s2[mip];
    int mxpp = calcMx(getMx(l, mxp - 1), getMx(mxp + 1, r));
    int mipp = calcMi(getMi(l, mxp - 1), getMi(mxp + 1, r));
    return max(s1[mxp] - s2[mipp], s1[mxpp] - s2[mip]);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &d[i % n + 1]), d[i % n + 1 + n] = d[i % n + 1];
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]), h[i + n] = h[i];

    LL sum = 0;
    s1[0] = -1e18;
    s2[0] = 1e18;
    for (int i = 1; i <= n * 2; i ++ )
    {
        sum += d[i];
        s1[i] = sum + 2 * h[i];
        s2[i] = sum - 2 * h[i];
    }

    build(1, 1, 2 * n);

    for (int i = 1; i <= m; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l <= r) printf("%lld\n", solve(r + 1, l - 1 + n));
        else printf("%lld\n", solve(r + 1, l - 1));
    }

    return 0;
}
