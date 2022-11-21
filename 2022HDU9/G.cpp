#include <bits/stdc++.h>

using namespace std;

const int N = 5005, mod = 998244353;

int n, k, r;
int a[N];
int f[N][N];
int x[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d%d", &n, &k, &r);
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d", &a[i]);
            if (a[1] > a[i] - r)
                x[i] = 0;
            else 
            {
                int L = 1, R = i - 1;
                while (L < R)
                {
                    int mid = (L + R + 1) >> 1;
                    if (a[mid] > a[i] - r) R = mid - 1;
                    else L = mid;
                }
                x[i] = L;
            }
        } 

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= k; j ++ )
                f[i][j] = (f[i - 1][j - 1] + 1LL * max(0, j - (i - 1 - x[i])) * f[i - 1][j] % mod ) % mod;
        
        printf("%d\n", f[n][k]);
    }
    return 0;
}