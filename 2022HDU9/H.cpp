#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 10000005, mod = 998244353;

int n, q;
int p[N];
bool vis[N];
int miu[N];
int P[105];
int ans;

void getprime()
{
    miu[1] = 1;
    for (int i = 2; i < N; i ++ )
    {
        if (!vis[i]) p[++ p[0]] = i, miu[i] = -1;
        for (int j = 1; j <= p[0] && 1LL * i * p[j] < N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                miu[i * p[j]] = 0;
                break;
            }
            miu[i * p[j]] = -miu[i];
        }
    }
}

int gcd(int a, int b)
{
    while (b)
    {
        int t = a;
        a = b;
        b = t % b;
    }
    return a;
}

void dfs(int i, LL x)
{
    if (i > P[0]) 
    {
        ans = (ans + 1LL * miu[x] * (n / x) % mod) % mod;
        return;
    }
    if (x * P[i] <= n) dfs(i + 1, x * P[i]);
    dfs(i + 1, x);
}

int main()
{
    getprime();

    scanf("%d%d", &n, &q);
    while (q -- )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (gcd(u, v) == 1) 
        {
            puts("1 1");
            continue;
        }
        set<int> s;
        int x = u;
        for (int i = 1; i <= p[0] && p[i] * p[i] <= x; i ++ )
        {
            if (x % p[i] == 0)
            {
                s.insert(p[i]);
                while (x % p[i] == 0) x /= p[i];
            }
        }
        if (x != 1) s.insert(x);
        x = v;
        for (int i = 1; i <= p[0] && p[i] * p[i] <= x; i ++ )
        {
            if (x % p[i] == 0)
            {
                s.insert(p[i]);
                while (x % p[i] == 0) x /= p[i];
            }
        }
        if (x != 1) s.insert(x);

        P[0] = 0;
        for (auto a : s) P[++ P[0]] = a;

        ans = 0;
        dfs(1, 1);
        if (gcd(u, v) == 2) ans = (ans + 1) % mod;
        printf("2 %d\n", ans);
    }

    return 0;
}