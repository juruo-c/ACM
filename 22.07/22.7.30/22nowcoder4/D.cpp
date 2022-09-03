#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <random>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 405, mod = 998244353;

int n, q, seed;
int f[N][N][N];
int bit[2000];

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

int solve(int a, int b, int c)
{
    return bit[f[a][b][c]];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &q);
    for (int i = 0; i < 1 << n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (i & (1 << j)) bit[i] ++;

    for (int i = 1; i <= n; i ++ )
    {
        int mi, a, b, c;
        scanf("%d", &mi);
        for (int j = 0; j < mi; j ++ )
        {
            scanf("%d%d%d", &a, &b, &c), f[a][b][c] |= (1 << (i - 1));
        }
    }
    
    scanf("%d", &seed);

    for (int i = 1; i <= 400; i ++ )
        for (int j = 1; j <= 400; j ++ )
            for (int k = 1; k <= 400; k ++ )
            {
                f[i][j][k] |= f[i - 1][j][k];
                f[i][j][k] |= f[i][j - 1][k];
                f[i][j][k] |= f[i][j][k - 1];
                f[i][j][k] |= f[i - 1][j - 1][k];
                f[i][j][k] |= f[i - 1][j][k - 1];
                f[i][j][k] |= f[i][j - 1][k - 1];
                f[i][j][k] |= f[i - 1][j - 1][k - 1];
                //printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
            }
    
    std::mt19937 rng(seed);
    std::uniform_int_distribution<> u(1,400);


    int lastans=0;
    int res = 0;
    for (int i=1;i<=q;i++)
    {
        int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
        int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
        int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
        lastans=solve(IQ,EQ,AQ);  // The answer to the i-th friend
        res = (res + 1LL * lastans * qpow(seed, q - i) % mod) % mod;
    }

    printf("%d\n", res);

    return 0;
}
