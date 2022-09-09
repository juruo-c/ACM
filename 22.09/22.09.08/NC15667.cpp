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

struct TreeNode
{
    int l, r;
    LL col, lz;
}t[N << 2];

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
}

void push_up(int i)
{
    t[i].col = t[i << 1].col | t[i << 1 | 1].col;
}

void push_down(int i)
{
    if (t[i].lz)
    {
        t[i << 1].lz |= t[i].lz;
        t[i << 1 | 1].lz |= t[i].lz;
        t[i << 1].col |= t[i].lz;
        t[i << 1 | 1].col |= t[i].lz;
        t[i].lz = 0;
    }
}

void update(int i, int l, int r, LL k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        t[i].lz |= k;
        t[i].col |= k;
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) update(i << 1, l, r, k);
    if (r > mid) update(i << 1 | 1, l, r, k);
    push_up(i);
}

LL query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].col;
    push_down(i);
    LL s = 0;
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) s |= query(i << 1, l, r);
    if (r > mid) s |= query(i << 1 | 1, l, r); 
    return s;
}

int get(LL x)
{
    int res = 0;
    for (int i = 0; i <= 60; i ++ )
        if (x >> i & 1) res ++;
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for (int i = 1; i <= m; i ++ )
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            int c;
            scanf("%d", &c);
            update(1, l, r, 1LL << c);
        }
        else printf("%d\n", get(query(1, l, r)));
    }
    return 0;
}
