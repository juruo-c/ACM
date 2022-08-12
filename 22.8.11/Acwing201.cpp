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

const int N = 1005, mod = 1000000007;

int p[N], phi[N];
bool vis[N];

void getphi(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!vis[i])
        {
            p[++ p[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= p[0] && i * p[j] <= n; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    phi[2] --;
    for (int i = 3; i <= n; i ++ )
        phi[i] = phi[i] - 1 + phi[i - 1];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    getphi(N - 5);
    int t; scanf("%d", &t);
    int kase = 0;
    while (t --)
    {
        int n;
        scanf("%d", &n);
        if (n == 1) printf("%d %d %d\n", ++ kase, n, 3);
        else 
        {
            int ans = 3 + (n - 1) * 2 + 2 * phi[n];
            printf("%d %d %d\n", ++ kase, n, ans);
        }
    }
    return 0;
}
