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

const int N = 200005, M = 20000005;

struct TreeNode
{
    int l, r;
}t[M];
int rt[105], id;
int ans[N];

void make(int& i, int l, int r)
{
    if (i) return;
    i = ++ id;
}

void updatePos(int& i, int l, int r, int pos)
{
    make(i, l, r);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) updatePos(t[i].l, l, mid, pos);
    else updatePos(t[i].r, mid + 1, r, pos);
}

int Merge(int i, int j)
{
    if (!i || !j) return i | j;
    t[i].l = Merge(t[i].l, t[j].l);
    t[i].r = Merge(t[i].r, t[j].r);
    return i;
}

void updateRange(int& i, int& j, int l, int r, int L, int R)
{
    if (!i) return;
    if (L <= l && r <= R)
    {
        j = Merge(i, j);
        i = 0;
        return;
    }
    make(j, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) updateRange(t[i].l, t[j].l, l, mid, L, R);
    if (R > mid) updateRange(t[i].r, t[j].r, mid + 1, r, L, R);
}

void solve(int i, int l, int r, int k)
{
    if (!i) return;
    if (l == r)
    {
        ans[l] = k;
        return;
    }
    int mid = (l + r) >> 1;
    solve(t[i].l, l, mid, k);
    solve(t[i].r, mid + 1, r, k);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        updatePos(rt[x], 1, n, i);
    }

    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ )
    {
        int l, r, x, y;
        scanf("%d%d%d%d", &l, &r, &x, &y);
        if (x == y) continue;
        updateRange(rt[x], rt[y], 1, n, l, r);
    }

    for (int i = 1; i <= 100; i ++ )
        solve(rt[i], 1, n, i);
    
    for (int i = 1; i <= n; i ++ )
        printf("%d ", ans[i]);
    puts("");

    return 0;
}
