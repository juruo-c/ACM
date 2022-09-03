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

const int N = 100005;

int a[N];

struct Tree
{
    int l, r;
    int s1, s0;
    int mx1, mx0;
    int lmx1, rmx1;
    int lmx0, rmx0;
    int setlz, revlz;
}t[N << 2];

void push_up(int i)
{
    t[i].s1 = t[i << 1].s1 + t[i << 1 | 1].s1;
    t[i].s0 = t[i << 1].s0 + t[i << 1 | 1].s0;

    t[i].mx1 = max(t[i << 1].mx1, t[i << 1 | 1].mx1);
    t[i].mx1 = max(t[i << 1].rmx1 + t[i << 1 | 1].lmx1, t[i].mx1);
    t[i].lmx1 = t[i << 1].lmx1;
    if (t[i].lmx1 == t[i << 1].r - t[i << 1].l + 1) t[i].lmx1 += t[i << 1 | 1].lmx1;
    t[i].rmx1 = t[i << 1 | 1].rmx1;
    if (t[i].rmx1 == t[i << 1 | 1].r - t[i << 1 | 1].l + 1) t[i].rmx1 += t[i << 1].rmx1;

    t[i].mx0 = max(t[i << 1].mx0, t[i << 1 | 1].mx0);
    t[i].mx0 = max(t[i << 1].rmx0 + t[i << 1 | 1].lmx0, t[i].mx0);
    t[i].lmx0 = t[i << 1].lmx0;
    if (t[i].lmx0 == t[i << 1].r - t[i << 1].l + 1) t[i].lmx0 += t[i << 1 | 1].lmx0;
    t[i].rmx0 = t[i << 1 | 1].rmx0;
    if (t[i].rmx0 == t[i << 1 | 1].r - t[i << 1 | 1].l + 1) t[i].rmx0 += t[i << 1].rmx0;
}

void Set(int i, int tag)
{
    if (tag)
    {
        t[i].s0 = t[i].mx0 = t[i].rmx0 = t[i].lmx0 = 0;
        t[i].s1 = t[i].mx1 = t[i].rmx1 = t[i].lmx1 = t[i].r - t[i].l + 1;
    }
    else 
    {
        t[i].s0 = t[i].mx0 = t[i].rmx0 = t[i].lmx0 = t[i].r - t[i].l + 1;
        t[i].s1 = t[i].mx1 = t[i].rmx1 = t[i].lmx1 = 0;
    }
    t[i].setlz = tag;
    t[i].revlz = 0;
}

void Rev(int i)
{
    swap(t[i].s0, t[i].s1);
    swap(t[i].lmx0, t[i].lmx1);
    swap(t[i].rmx0, t[i].rmx1);
    swap(t[i].mx0, t[i].mx1);
    t[i].revlz ^= 1;
}

void push_down(int i)
{
    if (t[i].setlz != -1) 
        Set(i << 1, t[i].setlz), Set(i << 1 | 1, t[i].setlz), t[i].setlz = -1;
    if (t[i].revlz)
        Rev(i << 1), Rev(i << 1 | 1), t[i].revlz = 0;
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    t[i].setlz = -1;
    if (l == r)
    {
        if (a[l])
            t[i].s1 = t[i].mx1 = t[i].lmx1 = t[i].rmx1 = 1;
        else
            t[i].s0 = t[i].mx0 = t[i].lmx0 = t[i].rmx0 = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void updateSet(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r) 
    {
        Set(i, k);
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) updateSet(i << 1, l, r, k);
    if (r > mid) updateSet(i << 1 | 1, l, r, k);
    push_up(i);
}

void updateRev(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        Rev(i);
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) updateRev(i << 1, l, r);
    if (r > mid) updateRev(i << 1 | 1, l, r);
    push_up(i);
}

int querySum(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].s1;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    int s = 0;
    if (l <= mid) s += querySum(i << 1, l, r);
    if (r > mid) s += querySum(i << 1 | 1, l, r);
    return s;
}

Tree queryMx(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i];
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l > mid) return queryMx(i << 1 | 1, l, r);
    else if( r <= mid) return queryMx(i << 1, l, r);
    else 
    {
        Tree ans;
        Tree ls = queryMx(i << 1, l, r), rs = queryMx(i << 1 | 1, l, r);
        ans.s1 = ls.s1 + rs.s1;
        ans.s0 = ls.s0 + rs.s0;
        ans.mx1 = max(ls.mx1, rs.mx1);
        ans.mx1 = max(ls.rmx1 + rs.lmx1, ans.mx1);
        ans.lmx1 = ls.lmx1;
        if (ans.lmx1 == ls.r - ls.l + 1) ans.lmx1 += rs.lmx1;
        ans.rmx1 = rs.rmx1;
        if (ans.rmx1 == rs.r - rs.l + 1) ans.rmx1 += ls.rmx1;

        ans.mx0 = max(ls.mx0, rs.mx0);
        ans.mx0 = max(ls.rmx0 + rs.lmx0, ans.mx0);
        ans.lmx0 = ls.lmx0;
        if (ans.lmx0 == ls.r - ls.l + 1) ans.lmx0 += rs.lmx0;
        ans.rmx0 = rs.rmx0;
        if (ans.rmx0 == rs.r - rs.l + 1) ans.rmx0 += ls.rmx0;
        return ans;
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    build(1, 1, n);

    // printf("sum = %d\n", querySum(1, 1, 6));

    for (int i = 1; i <= m; i ++ )
    {
        int op;
        int l, r;
        scanf("%d%d%d", &op, &l, &r);
        l ++, r ++;
        if (op == 0) updateSet(1, l, r, 0);
        else if(op == 1) updateSet(1, l, r, 1);
        else if(op == 2) updateRev(1, l, r);
        else if(op == 3) printf("%d\n", querySum(1, l, r));
        else printf("%d\n", queryMx(1, l, r).mx1);
    }

    return 0;
}
