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

int a[N], pre[N];
int pos[N * 2];
LL ans[N];
struct TreeNode
{
    int l, r;
    LL mx, mx_his;
    LL addlz, add_his;
}t[N << 2];
struct Query
{
    int l, r, id;
    bool operator < (const Query& b) const 
    {
        return r < b.r;
    }
}q[N];

void push_up(int i)
{
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].mx_his = max(t[i << 1].mx_his, t[i << 1 | 1].mx_his);
}

void Add(int i, LL add, LL his_add)
{
    t[i].add_his = max(t[i].add_his, t[i].addlz + his_add);
    t[i].mx_his = max(t[i].mx_his, t[i].mx + his_add);
    t[i].mx += add;
    t[i].addlz += add;
}

void push_down(int i)
{
    Add(i << 1, t[i].addlz, t[i].add_his);
    Add(i << 1 | 1, t[i].addlz, t[i].add_his);
    t[i].add_his = t[i].addlz = 0;
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void update(int i, int l, int r, LL k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        Add(i, k, k);
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
    if (l <= t[i].l && t[i].r <= r) return t[i].mx_his;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    LL mx = -1e18;
    if (l <= mid) mx = max(mx, query(i << 1, l, r));
    if (r > mid) mx = max(mx, query(i << 1 | 1, l, r));
    return mx;
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
        scanf("%d", &a[i]);
    build(1, 1, n);
    
    for (int i = 1; i <= n; i ++ )
    {
        pre[i] = pos[a[i] + 100000];
        pos[a[i] + 100000] = i;
    }

    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ )
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }

    sort(q + 1, q + 1 + m);

    int cur = 1;
    for (int i = 1; i <= n; i ++ )
    {
        update(1, pre[i] + 1, i, a[i]);
        while(cur <= m && q[cur].r <= i)
            ans[q[cur].id] = query(1, q[cur].l, q[cur].r), cur ++;
    }

    for (int i = 1; i <= m; i ++ )
        printf("%lld\n", ans[i]);

    return 0;
}
