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

const int N = 100, mod = 998244353;

int n;
int W, H;
struct RET
{
    int x1, y1, x2, y2;
}ret[N];

struct Seq
{
    int x, y1, y2;
    int v;
    Seq(double x = 0, double y1 = 0, double y2 = 0, int v = 0):x(x), y1(y1), y2(y2), v(v){}
    bool operator < (const Seq& s) const{
        return x < s.x;
    }
}seq[N];
int seq_cnt;

struct TreeNode
{
    int l, r;
    double len;
    int sum;
}t[N << 2];
int b[N], b_cnt;
int cnt;

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

int getnum(int x)
{
    return lower_bound(b + 1, b + 1 + cnt, x) - b;
}

bool st[1 << 10];
int f[1 << 10];

bool check(int x)
{
    seq_cnt = 0;
    b_cnt = 0;
    for (int i = 0; i < n; i ++ )
        if (x >> i & 1)
        {
            seq[++ seq_cnt] = Seq(ret[i].x1, ret[i].y1, ret[i].y2, 1);
            seq[++ seq_cnt] = Seq(ret[i].x2, ret[i].y1, ret[i].y2, -1);
            b[++ b_cnt] = ret[i].y1;
            b[++ b_cnt] = ret[i].y2;
        }
    sort(seq + 1, seq + 1 + seq_cnt);
    sort(b + 1, b + 1 + b_cnt);
    cnt = unique(b + 1, b + 1 + b_cnt) - b - 1;
    build(1, 1, cnt);

    LL ans = 0;
    for (int i = 1; i < seq_cnt; i ++ )
    {
        int l = getnum(seq[i].y1), r = getnum(seq[i].y2) - 1;
        update(1, l, r, seq[i].v);
        ans += 1LL * t[1].len * (seq[i + 1].x - seq[i].x);
    }

    return ans == 1LL * W * H;
}

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        scanf("%d%d", &W, &H);
        for (int i = 0; i < n; i ++ )
        {
            scanf("%d%d%d%d", &ret[i].x1, &ret[i].y1, &ret[i].x2, &ret[i].y2);
            ret[i].x1 = max(ret[i].x1, 0);
            ret[i].y1 = max(ret[i].y1, 0);
            ret[i].x2 = min(ret[i].x2, W);
            ret[i].y2 = min(ret[i].y2, H);
        }
        
        for (int i = 1; i < 1 << n; i ++ )
            st[i] = check(i);

        if (!st[(1 << n) - 1])
        {
            puts("-1");
            continue;
        }

        memset(f, 0, sizeof f);
        for (int i = (1 << n) - 1; i >= 0; i -- )
        {
            if (st[i]) continue;
            int c1 = 0;
            int res = 0;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1)
                    c1 ++;
                else res = (res + f[i + (1 << j)] + 1) % mod;
            f[i] = 1LL * (res + c1) % mod * qpow(n - c1, mod - 2) % mod;
        }

        printf("%d\n", f[0]);
    }
    return 0;
}
