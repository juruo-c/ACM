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

const int N = 400005, mod = 1000000007;

int n, m;
int a[N];
int p[305];
bool vis[305];

struct Tree
{
    int l, r;
    LL pstate; int mul;
    LL plz; int mullz;
}t[N << 2];

void get_prime(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!vis[i]) p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] <= n; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
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

void push_up(int i)
{
    t[i].mul = 1LL * t[i << 1].mul * t[i << 1 | 1].mul % mod;
    t[i].pstate = t[i << 1].pstate | t[i << 1 | 1].pstate;
}

void calc(int i, int mul, LL state)
{
    t[i].mul = 1LL * t[i].mul * qpow(mul, t[i].r - t[i].l + 1) % mod;
    t[i].pstate |= state;
    t[i].mullz = 1LL * t[i].mullz * mul % mod;
    t[i].plz |= state;
}

void push_down(int i)
{
    if (!t[i].plz) return;
    int mul = t[i].mullz;
    LL state = t[i].plz;
    calc(i << 1, mul, state);
    calc(i << 1 | 1, mul, state);
    // t[i << 1].mul = 1LL * t[i << 1].mul * qpow(mul, t[i << 1].r - t[i << 1].l + 1) % mod;
    // t[i << 1 | 1].mul = 1LL * t[i << 1 | 1].mul * qpow(mul, t[i << 1 | 1].r - t[i << 1 | 1].l + 1) % mod;
    // t[i << 1].pstate |= state;
    // t[i << 1 | 1].pstate |= state;
    // t[i << 1].mullz = 1LL * t[i << 1].mullz * mul % mod;
    // t[i << 1 | 1].mullz = 1LL * t[i << 1 | 1].mullz * mul % mod;
    // t[i << 1].plz |= state;
    // t[i << 1 | 1].plz |= state;
    t[i].plz = 0, t[i].mullz = 1;    
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    t[i].mul = 1, t[i].mullz = 1;
    if (l == r)
    {
        int x = a[l];
        t[i].mul = x;
        for (int j = 1; j <= p[0]; j ++ )
            if (x % p[j] == 0)
                t[i].pstate |= 1LL << (j - 1);
        // cout << "x = " << x << " mul = " << t[i].mul << " pstate = " << t[i].pstate << endl;
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void update(int i, int l, int r, int x, LL xp)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        calc(i, x, xp);
        // t[i].mul = 1LL * t[i].mul * qpow(x, t[i].r - t[i].l + 1) % mod;
        // t[i].pstate |= xp;
        // t[i].mullz = 1LL * t[i].mullz * x % mod;
        // t[i].plz |= xp;
        return;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) update(i << 1, l, r, x, xp);
    if (r > mid) update(i << 1 | 1, l, r, x, xp);
    push_up(i);
}

pair<LL, int> query(int i, int l, int r)
{
    if (l <= t[i].l && t[i].r <= r)
    {
        pair<LL, int> tt = make_pair(t[i].pstate, t[i].mul);
        return tt;
    }
    push_down(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l > mid) return query(i << 1 | 1, l, r);
    else if (r <= mid) return query(i << 1, l, r);
    else 
    {
        pair<LL, int> ls = query(i << 1, l, r);
        pair<LL, int> rs = query(i << 1 | 1, l, r);
        ls.first |= rs.first;
        ls.second = 1LL * ls.second * rs.second % mod;
        return ls;
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    get_prime(300);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);

    build(1, 1, n);

    // cout << query(1, 3, 3, 1) << endl;

    
    for (int i = 1; i <= m; i ++ )
    {
        char s[10];
        scanf("%s", s);
        if (s[0] == 'T') 
        {
            int l, r;
            scanf("%d%d", &l, &r);
            pair<LL, int> t = query(1, l, r);
            int ans = t.second;
            LL pstate = t.first;
            // cout << "pstate = " << pstate << " t.second = " << t.second << endl;
            for (int j = 1; j <= p[0]; j ++ )
                if (pstate & (1LL << (j - 1)))
                    ans = 1LL * ans * (p[j] - 1) % mod * qpow(p[j], mod - 2) % mod;
            printf("%d\n", ans);
        }
        else 
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            LL xp = 0;
            for (int j = 1; j <= p[0]; j ++ )
                if (x % p[j] == 0) 
                    xp += (1LL << (j - 1));
            update(1, l, r, x, xp);
        }
    }
    return 0;
}
