#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005, mod = 1000000007;

int n, m;
int a[N * 2];
int sum[N * 2];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]), a[i + n] = a[i];
    
    int t = n;
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        sum[i] = (sum[i - 1] + a[i]) % mod;
        ans = (ans + sum[i]) % mod;
    }
    
    int s = sum[n];
    for (int i = 1; i <= m; i ++ )
    {
        ans = (2 * ans % mod + 1LL * s * n % mod) % mod;
        n = n * 2 % mod;
        s = s * 2 % mod;
    }
    
    n = t;
    int res = 0;
    for (int i = 1, j = 2 * n; i <= n; i ++ , j -- )
        a[i] = a[j];

    n = n * 2;
    for (int i = 1; i <= n; i ++ )
    {
        sum[i] = (sum[i - 1] + a[i]) % mod;
        res = (res + sum[i]) % mod;
    }
    s = sum[n];
    for (int i = 2; i <= m; i ++ )
    {
        res = (2 * res % mod + 1LL * s * n % mod) % mod;
        n = n * 2 % mod;
        s = s * 2 % mod;
    }

    printf("%d\n", max(res, ans));

    return 0;
}