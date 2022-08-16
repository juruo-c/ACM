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

const int N = 100005, mod = 1000000007;

int n, q;
int a[N];
int block, block_id[N];
struct Query
{
    int l, r, id;

    bool operator < (const Query& q) const
    {
        if (block_id[l] == block_id[q.l]) 
        {
            if (block_id[l] & 1)
                return r < q.r;
            else return r > q.r;
        }
        return block_id[l] < block_id[q.l];
    }
}query[N];
LL ans[N];
LL cur;
int cnt[2][N * 10];

void add(int x, int id)
{
    cur += cnt[id & 1][x];
    cnt[id & 1][x] ++;
}

void del(int x, int id)
{
    cnt[id & 1][x] --;
    cur -= cnt[id & 1][x];
}

LL calc(int n)
{
    return 1LL * n * (n + 1) / 2;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]), a[i] --, a[i] ^= a[i - 1];
    for (int i = 1; i <= q; i ++ )
        scanf("%d%d", &query[i].l, &query[i].r), query[i].l --, query[i].id = i;

    block = (int) sqrt(n);
    for (int i = 1; i <= n; i ++ )
        block_id[i] = (i - 1) / block + 1;
    sort(query + 1, query + 1 + q);

    for (int i = 1, l = 1, r = 0; i <= q; i ++ )
    {
        if (query[i].l == query[i].r)
        {
            ans[query[i].id] = 1;
            continue;
        }
        while (l > query[i].l) 
            l --, add(a[l], l);
        while (r < query[i].r)
            r ++, add(a[r], r);
        while (l < query[i].l)
            del(a[l], l), l ++;
        while (r > query[i].r) 
            del(a[r], r), r --;
        ans[query[i].id] = calc(query[i].r - query[i].l) - cur;
    }

    for (int i = 1; i <= q; i ++ )
        printf("%lld\n", ans[i]);

    return 0;
}
