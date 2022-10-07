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

int n, q;
struct Tree
{
    int l, r;
    LL sum, lz;
    int cnt;
}t[N << 2];
int a[N], s[N];

void push_up(int i)
{
    t[i].cnt = t[i << 1].cnt + t[i << 1 | 1].cnt;
    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void push_down(int i)
{
    if (t[i].lz)
    {
        t[i << 1].lz += t[i].lz;
        t[i << 1 | 1].lz += t[i].lz;
        t[i << 1].sum += t[i].lz * t[i << 1].cnt;
        t[i << 1 | 1].sum += t[i].lz * t[i << 1 | 1].cnt;
        t[i].lz = 0;
    }
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r) 
    {
        t[i].sum = a[l];
        t[i].cnt = s[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void updateCnt(int i, int pos, int k)
{
    if (t[i].l == t[i].r)
    {
        t[i].cnt += k;
        return; 
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (pos <= mid) updateCnt(i << 1, pos, k);
    else updateCnt(i << 1 | 1, pos, k);
    push_up(i);
}

void updateSum(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        t[i].sum += 1LL * t[i].cnt * k;
        t[i].lz += k;
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) updateSum(i << 1, l, r, k);
    if (r > mid) updateSum(i << 1 | 1, l, r, k);
    push_up(i);
}

LL query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].sum;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    LL sum = 0;
    if (l <= mid) sum += query(i << 1, l, r);
    if (r > mid) sum += query(i << 1 | 1, l, r);
    return sum;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &s[i]);

    build(1, 1, n);

    for (int i = 1; i <= q; i ++ )
    {
        int op;
        scanf("%d", &op);
        if (op == 1 || op == 2)
        {
            int x;
            scanf("%d", &x);
            updateCnt(1, x, (op == 1 ? -1 : 1));
        }
        else if(op == 3)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            updateSum(1, l, r, x);
        }
        else if (op == 4)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }

    return 0;
}
