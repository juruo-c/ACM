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

struct TreeNode
{
    int l, r;
    int mx, mx_his;
    int addlz, setlz;
    int add_his, set_his;
    bool has_set;
}t[N << 2];

void push_up(int i)
{
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].mx_his = max(t[i << 1].mx_his, t[i << 1 | 1].mx_his);
}

void push_Add(int i, int add, int his_add)
{
    t[i].mx_his = max(t[i].mx + his_add, t[i].mx_his);
    t[i].add_his = max(t[i].addlz + his_add, t[i].add_his);
    t[i].mx += add;
    t[i].addlz += add; 
}

void push_Set(int i, int set, int his_set)
{
    if (t[i].has_set)
    {
        t[i].mx = set;
        t[i].setlz = set;
        t[i].mx_his = max(his_set, t[i].mx_his);
        t[i].set_his = max(t[i].set_his, his_set);
    }
    else 
    {
        t[i].has_set = true;
        t[i].mx = set;
        t[i].setlz = set;
        t[i].mx_his = max(his_set, t[i].mx_his);
        t[i].set_his = his_set;
    }
}

void push_down(int i)
{
    if (t[i << 1].has_set)
        push_Set(i << 1, t[i << 1].setlz + t[i].addlz, t[i << 1].setlz + t[i].add_his);
    else 
        push_Add(i << 1, t[i].addlz, t[i].add_his);
    if (t[i << 1 | 1].has_set)
        push_Set(i << 1 | 1, t[i << 1 | 1].setlz + t[i].addlz, t[i << 1 | 1].setlz + t[i].add_his);
    else 
        push_Add(i << 1 | 1, t[i].addlz, t[i].add_his);
    if (t[i].has_set)
    {
        push_Set(i << 1, t[i].setlz, t[i].set_his);
        push_Set(i << 1 | 1, t[i].setlz, t[i].set_his);
    }

    t[i].has_set = false;
    t[i].addlz = t[i].add_his = t[i].setlz = t[i].set_his = 0;
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r)
    {
        t[i].mx = t[i].mx_his = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void updateAdd(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r) 
    {
        if (t[i].has_set)
            push_Set(i, t[i].setlz + k, t[i].setlz + k);
        else 
            push_Add(i, k, k);
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) updateAdd(i << 1, l, r, k);
    if (r > mid) updateAdd(i << 1 | 1, l, r, k);
    push_up(i);
}

void updateSet(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        push_Set(i, k, k);
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) updateSet(i << 1, l, r, k);
    if (r > mid) updateSet(i << 1 | 1, l, r, k);
    push_up(i);
}

int queryMx(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].mx;
    push_down(i);
    int s = -0x3f3f3f3f;
    int mid = (t[i].l + t[i].r ) >> 1;
    if (l <= mid) s = max(s, queryMx(i << 1, l, r));
    if (r > mid) s = max(s, queryMx(i << 1 | 1, l, r));
    return s;
}

int queryHisMx(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r) return t[i].mx_his;
    push_down(i);
    int s = -0x3f3f3f3f;
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) s = max(s, queryHisMx(i << 1, l, r));
    if (r > mid) s = max(s, queryHisMx(i << 1 | 1, l, r));
    return s;
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

    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ )
    {
        char op;
        int l, r, x;
        scanf("\n%c", &op);
        scanf("%d%d", &l, &r);
        if (op == 'A') printf("%d\n", queryHisMx(1, l, r));
        else if(op == 'Q') printf("%d\n", queryMx(1, l, r));
        else if(op == 'P')
        {
            scanf("%d", &x);
            updateAdd(1, l, r, x);
        }
        else if(op == 'C')
        {
            scanf("%d", &x);
            updateSet(1, l, r, x);
        }
    }
    return 0;
}
