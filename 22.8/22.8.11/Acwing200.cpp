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

const int N = 44750, mod = 1000000007;

bool vis[N + 5];
int p[N + 5];
PII factor[N];
int fac_cnt;
int divisor[N];
int div_cnt;

void getprime()
{
    for (int i = 2; i <= N; i ++ )
    {
        if (!vis[i])
            p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] <= N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

void getfactor(int n)
{
    fac_cnt = 0;
    for (int i = 1; i <= p[0] && p[i] * p[i] <= n; i ++ )
    {
        int t = p[i];
        if (n % t == 0)
        {
            int cnt = 0;
            while (n % t == 0)
                cnt ++, n /= t;
            factor[++ fac_cnt] = make_pair(t, cnt);
        }
    }
    if (n > 1) factor[++ fac_cnt] = make_pair(n, 1);
}

void dfs(int depth, int tmp)
{
    if (depth > fac_cnt)
    {
        divisor[++ div_cnt] = tmp;
        return;
    }
    for (int i = 0; i <= factor[depth].second; i ++ )
        dfs(depth + 1, tmp), tmp *= factor[depth].first;
}

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

LL lcm(int a, int b)
{
    return 1LL * a * b / gcd(a, b);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    getprime();
    int t; scanf("%d", &t);
    while (t --)
    {
        int a0, a1, b0, b1;
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);

        getfactor(b1);

        div_cnt = 0;
        dfs(1, 1);

        int ans = 0;
        for (int i = 1; i <= div_cnt; i ++ )
        {
            if (lcm(divisor[i], b0) == b1 && gcd(divisor[i], a0) == a1) ans ++;
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
