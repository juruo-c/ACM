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

const int N = 500005, INF = 0x3f3f3f3f;

int n, m;
int a[N];
int ans[N];
int pos[N];
struct Query
{
    int l, r, id;
    bool operator < (const Query& b) const 
    {
        return r < b.r;
    } 
}q[N];
struct Data
{
    int pos, num;
    Data(){}
    Data (int pos, int num): pos(pos), num(num){}
    bool operator < (const Data& b) const 
    {
        return pos < b.pos;
    }
}inf(INF, 0);

struct Tree
{
    int l, r;
    Data mi;
}t[N << 2];

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    t[i].mi = {INF, 0};
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
}

void push_up(int i)
{
    t[i].mi = min(t[i << 1].mi, t[i << 1 | 1].mi);
}

void update(int i, int pos, Data& k)
{
    if (t[i].l == t[i].r)
    {
        t[i].mi = k;
        return;
    }
    int mid = (t[i].l + t[i].r) >> 1;
    if (pos <= mid) update(i << 1, pos, k);
    else update(i << 1 | 1, pos, k);
    push_up(i);
}

Data query(int i, int l, int r)
{
    // cout << t[i].l << " " << t[i].r << endl;
    if (l <= t[i].l && t[i].r <= r) return t[i].mi;
    Data s = inf;
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) s = min(query(i << 1, l, r), s);
    if (r > mid) s = min(query(i << 1 | 1, l, r), s);
    return s;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);

    build(1, 1, n);

    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ )
        scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
    sort(q + 1, q + 1 + m);

    int cur = 1;
    for (int i = 1; i <= n; i ++ )
    {
        int x = a[i];
        if (pos[x])
        {
            update(1, pos[x], inf);
            Data t(pos[x], x);
            update(1, i, t);
        }
        else 
        {
            Data t(0, x);
            update(1, i, t);
        }
        pos[x] = i;

        while (cur <= m && q[cur].r <= i)
        {
            Data t = query(1, q[cur].l, q[cur].r);
            // cout << "over" << endl;
            if (t.pos < q[cur].l) 
                ans[q[cur].id] = t.num;
            cur ++;
        }
    }

    for (int i = 1; i <= m; i ++ )
        printf("%d\n", ans[i]);

    return 0;
}
