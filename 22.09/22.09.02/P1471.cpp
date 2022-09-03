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

int n, m;
double a[N];

struct Tree
{
    int l, r;
    double s1, s2;
    double lz;
}t[N << 2];

void push_up(int i)
{
    t[i].s1 = t[i << 1].s1 + t[i << 1 | 1].s1;
    t[i].s2 = t[i << 1].s2 + t[i << 1 | 1].s2;
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r)
    {
        t[i].s1 = a[l];
        t[i].s2 = a[l] * a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void calc(int i, double add)
{
    t[i].lz += add;
    t[i].s2 += 2 * add * t[i].s1 + add * add * (t[i].r - t[i].l + 1);
    t[i].s1 += add * (t[i].r - t[i].l + 1); 
}

void push_down(int i)
{
    if (t[i].lz == 0) return;
    double add = t[i].lz;
    calc(i << 1, add);
    calc(i << 1 | 1, add);
    t[i].lz = 0;
}

void update(int i, int l, int r, double k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        calc(i, k);
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) update(i << 1, l, r, k);
    if (r > mid) update(i << 1 | 1, l, r, k);
    push_up(i);
}

double query1(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
        return t[i].s1;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    double s = 0;
    if (l <= mid) s += query1(i << 1, l, r);
    if (r > mid) s += query1(i << 1 | 1, l, r);
    return s;
}

double query2(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
        return t[i].s2;
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    double s = 0;
    if (l <= mid) s += query2(i << 1, l, r);
    if (r > mid) s += query2(i << 1 | 1, l, r);
    return s;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%lf", &a[i]);
    build(1, 1, n);
    
    for (int i = 1; i <= m; i ++ )
    {
        int op;
        int l, r;
        double k;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            scanf("%lf", &k);
            update(1, l, r, k);
        }
        else if (op == 2)
            printf("%.4f\n", query1(1, l, r) / (r - l + 1));
        else if (op == 3){
            double t = query1(1, l, r) / (r - l + 1);
            printf("%.4f\n", query2(1, l, r) / (r - l + 1) - t * t);
        }
            
    }
    return 0;
}
