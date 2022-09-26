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

const int N = 1000005, mod = 1000000007;

struct Seq
{
    int l, r;
    int len;
    bool operator < (const Seq& b) const 
    {
        if (l == b.l) return r > b.r;
        return l < b.l;
    }
}a[N];
int seq_cnt;
int fa[N];
int jc[N];

struct edge
{
    int to, next;
}e[N];
int head[N], cnt;

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

int dfs(int u)
{
    int res = 1;
    int len = 0;
    int cnt = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        res = 1LL * res * dfs(v) % mod;
        len += a[v].len;
        cnt ++;
    }
    res = 1LL * res * jc[cnt + a[u].len - len] % mod;
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
    set<PII> s;
    for (int i = 1; i <= m; i ++ )
    {
        PII t;
        scanf("%d%d", &t.first, &t.second);
        s.insert(t);
    }
    s.insert(make_pair(1, n));

    for (set<PII>::iterator it = s.begin(); it != s.end(); it ++ )
        a[++ seq_cnt] = {it->first, it->second, it->second - it->first + 1};
    
    sort(a + 1, a + 1 + seq_cnt);

    int p = 1;
    for (int i = 2; i <= seq_cnt; i ++ )
    {
        while (a[p].l > a[i].l || a[i].r > a[p].r)
            p = fa[p];
        fa[i] = p;
        add(fa[i], i);
        p = i;
    }

    jc[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;

    printf("%d\n", dfs(1));

    return 0;
}
