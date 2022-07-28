#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1000005, mod = 1000000007;

int n;
char s[N];
struct edge
{
    int to, next;
}e[N];
int head[N], cnt;
int siz[N];

struct SAM
{
    int ch[N][26], fa[N], len[N];
    int last, tot;

    void init()
    {
        last = tot = 1;
        memset(ch, 0, sizeof ch);
        memset(len, 0, sizeof len);
        memset(fa, 0, sizeof fa);
    }

    void add(int c)
    {
        int p = last;
        int np = last = ++ tot;
        len[np] = len[p] + 1;
        siz[tot] = 1;
        for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if (!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if (len[q] == len[p] + 1) fa[np] = q;
            else 
            {
                int nq = ++ tot;
                memcpy(ch[nq], ch[q], sizeof ch[q]);
                fa[nq] = fa[q];
                len[nq] = len[p] + 1;
                fa[np] = fa[q] = nq;
                for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            }
        }
    }

}sam;

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

LL ans;

void dfs(int u)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        dfs(v);
        siz[u] += siz[v];
    }
    ans += 1LL * (sam.len[u] - sam.len[sam.fa[u]]) * siz[u] * (n - siz[u]);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        sam.init();
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = n; i >= 1; i -- )
            sam.add(s[i] - 'a');

        for (int i = 1; i <= sam.tot; i ++ )
            add(sam.fa[i], i);

        dfs(1);

        printf("%lld\n", ans);

    }
    return 0;
}
