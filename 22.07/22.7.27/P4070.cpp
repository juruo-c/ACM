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

const int N = 200005, mod = 1000000007;

struct SAM
{
    map<int, int> ch[N];
    int len[N], fa[N];
    int last, tot;

    void init()
    {
        last = tot = 1;
        for (int i = 0; i < N; i ++ ) ch[i].clear();
        memset(len, 0, sizeof len);
        memset(fa, 0, sizeof fa);
    }

    int add(int c)
    {
        int p = last;
        int np = last = ++ tot;
        len[np] = len[p] + 1;
        for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if (!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if (len[q] == len[p] + 1) fa[np] = q;
            else
            {
                int nq = ++ tot;
                ch[nq] = ch[q];
                fa[nq] = fa[q];
                len[nq] = len[p] + 1;
                fa[q] = fa[np] = nq;
                for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            }
        }
        
        return np;
    }
}sam;

int n;

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
        scanf("%d", &n);
        LL ans = 0;
        for (int i = 1; i <= n; i ++ )
        {
            int x;
            scanf("%d", &x);
            int t = sam.add(x);
            ans += sam.len[t] - sam.len[sam.fa[t]];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
