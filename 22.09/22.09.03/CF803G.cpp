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

const int N = 100005, M = 20000005;

int n, k, q;
struct Tree
{
    int l, r;
    int mi, lz;
}t[M];
int rt, id;
int st[N][30];

int st_query(int l, int r)
{
    int k = log2(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int getMin(int l, int r)
{
    // cout << "l = " << l << "r = " << r << endl;
    if (r - l + 1 >= n) 
    {
        // cout << st_query(0, n - 1) << endl;
        return st_query(0, n - 1);
    }
    if (r / n == l / n) return st_query(l % n, r % n);
    return min(st_query(l % n, n - 1), st_query(0, r % n));
}

bool make(int& x, int l, int r)
{   
    //动态创建节点（区间为[l, r]的节点）
    if (x) return false;
    x = ++id;
    t[x].mi = getMin(l, r);
    return true;
}

void st_init()
{
    for (int j = 1; j < 30; j ++ )
        for (int i = 0; i + (1 << j) - 1 < n; i ++ )
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

void push_down(int x, int l, int r)
{
    int mid = (l + r) >> 1;
    make(t[x].l, l, mid);
    make(t[x].r, mid + 1, r);
    if (!t[x].lz) return;
    t[t[x].l].mi = t[t[x].l].lz = t[t[x].r].mi = t[t[x].r].lz = t[x].lz;
    t[x].lz = 0;
}

void push_up(int x)
{
    t[x].mi = min(t[t[x].l].mi, t[t[x].r].mi);
}

void update(int& x, int l, int r, int L, int R, int k)
{
    // cout << l << " " << r << " " << (L <= l && r <= R) << endl;
    make(x, l, r);
    if (L <= l && r <= R) 
    {
        t[x].mi = t[x].lz = k;
        return;
    }
    push_down(x, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(t[x].l, l, mid, L, R, k);
    if (R > mid) update(t[x].r, mid + 1, r, L, R, k);
    push_up(x);
}

int query(int& x, int l, int r, int L, int R)
{
    make(x, l, r);
    if (L <= l && r <= R) return t[x].mi;
    push_down(x, l, r);
    int mid = (l + r) >> 1;
    int s = 0x3f3f3f3f;
    if (L <= mid) s = min(s, query(t[x].l, l, mid, L, R));
    if (R > mid) s = min(s, query(t[x].r, mid + 1, r, L, R));
    return s;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) scanf("%d", &st[i][0]);
    st_init();

    make(rt, 0, n * k - 1);
    scanf("%d", &q);
    for (int i = 1; i <= q; i ++ )
    {
        // cout << "i = " << i << endl;
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) 
        {
            int x;
            scanf("%d", &x);
            update(rt, 0, n * k - 1, l - 1, r - 1, x);
        }
        else printf("%d\n", query(rt, 0, n * k - 1, l - 1, r - 1));
    }

    return 0;
}
