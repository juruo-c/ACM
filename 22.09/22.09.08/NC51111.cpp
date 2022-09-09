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

const int N = 205;

struct Seq
{
    double x, y1, y2;
    int v;
    Seq(double x = 0, double y1 = 0, double y2 = 0, int v = 0):x(x), y1(y1), y2(y2), v(v){}
    bool operator < (const Seq& s) const 
    {
        return x < s.x;
    }
}seq[N];

struct TreeNode
{
    int l, r;
    double len;
    int sum;
}t[N << 2];

int n;
int cnt;
double b[N];

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    t[i].len = 0, t[i].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
}

void push_up(int i)
{
    if (t[i].sum) t[i].len = b[t[i].r + 1] - b[t[i].l];
    else if(t[i].l == t[i].r) t[i].len = 0;
    else t[i].len = t[i << 1].len + t[i << 1 | 1].len;
}

void update(int i, int l, int r, int k)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        t[i].sum += k;
        push_up(i);
        return;
    }
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) update(i << 1, l, r, k);
    if (r > mid) update(i << 1 | 1, l, r, k);
    push_up(i);
}

int getnum(double x)
{
    return lower_bound(b + 1, b + 1 + cnt, x) - b;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int kase = 0;
    while (scanf("%d", &n), n)
    {
        double x1, y1, x2, y2;
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seq[i * 2 - 1] = Seq(x1, y1, y2, 1);
            seq[i * 2] = Seq(x2, y1, y2, -1);
            b[i * 2 - 1] = y1;
            b[i * 2] = y2;
        }

        n *= 2;
        sort(seq + 1, seq + 1 + n);
        sort(b + 1, b + 1 + n);
        cnt = unique(b + 1, b + 1 + n) - b - 1;
        build(1, 1, cnt);

        double ans = 0;
        for (int i = 1; i < n; i ++ )
        {
            int l = getnum(seq[i].y1), r = getnum(seq[i].y2) - 1;
            update(1, l, r, seq[i].v);
            ans += t[1].len * (seq[i + 1].x - seq[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++ kase, ans);
    }
    return 0;
}
