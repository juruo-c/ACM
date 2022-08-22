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

bool vis[N];
int p[N], miu[N], f[N];

struct Query
{
    int n, m, a, id;
    bool operator < (const Query& q) const
    {
        return a < q.a;
    }
}q[N];
struct D
{
    int id;
    LL d;
    bool operator < (const D& b) const
    {
        return d < b.d;
    }
}d[N];
int ans[N];
int c[N];

void pre()
{
    miu[1] = 1;
    for (int i = 2; i < N; i ++ )
    {
        if (!vis[i])
        {
            p[ ++ p[0] ] = i;
            miu[i] = -1;
        }
        for (int j = 1; j <= p[0] && 1LL * i * p[j] < N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                miu[i * p[j]] = 0;
                break;
            }
            miu[i * p[j]] = - miu[i];
        }
    }
    for (int i = 1; i < N; i ++ )   
        for (int j = i; j < N; j += i)
            f[j] += i;
    for (int i = 1; i < N; i ++ )
        d[i].d = f[i], d[i].id = i;
    sort(d + 1, d + N);
    // for (int i = 1; i < N; i ++ )
    //     f[i] += f[i - 1];
}

void update(int x, int k)
{
    for (int i = x; i < N; i += (i & -i))
        c[i] += k;
}

int query(int x)
{
    int ans = 0;
    for (int i = x; i; i -= (i & -i))
        ans += c[i];
    return ans;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    pre();
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i ++ ) 
        scanf("%d%d%d", &q[i].n, &q[i].m, &q[i].a), q[i].id = i;

    sort(q + 1, q + 1 + t);
    
    int last = 1;
    for (int i = 1; i <= t; i ++ )
    {
        int a = q[i].a;
        while (last < N && d[last].d <= a)
        {
            for (int j = 1; j * d[last].id < N; j ++ )
                update(j * d[last].id, d[last].d * miu[j]);
            last ++;
            // printf("i = %d last = %d\n", i, last);
        }   
        int n = q[i].n, m = q[i].m;
        if (n > m) swap(n, m);
        int id = q[i].id;
        for (int l = 1, r; l <= n; l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ans[id] += (n / l) * (m / l) * (query(r) - query(l - 1));
        }
    }

    for (int i = 1; i <= t; i ++ )
        printf("%d\n", ans[i] & (~(1 << 31)));

    return 0;
}
