#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005, mod = 998244353;

int n, m, k;
int jc[N], jcInv[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int m)
{
    if (m > n) return 0;
    return 1LL * jc[n] * jcInv[m] % mod * jcInv[n - m] % mod;
}

int calc(int n, int m, int k)
{
    k ++;
    int ans = 0;
    int f = 1;
    for (int i = 0; i <= n; i ++ )
    {
        if (1LL * i * k > m + n - 1) break;
        ans = (ans + f * (1LL * C(n, i) * C(m + n - 1 - i * k, n - 1) % mod)) % mod, f *= -1, ans = (ans + mod) % mod;
    }
    return ans;
}

int main()
{
    cin >> n >> m >> k;

    if (n < m || m < k)
    {
        puts("0");
        return 0;
    }

    jc[0] = jcInv[0] = 1;
    for (int i = 1; i <= N - 1; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;
    jcInv[N - 1] = qpow(jc[N - 1], mod - 2);
    for (int i = N - 1 - 1; i >= 1; i -- )
        jcInv[i] = 1LL * (i + 1) * jcInv[i + 1] % mod;

    cout << (calc(n - m + 1, m, k) - calc(n - m + 1, m, k - 1) + mod) % mod << endl;

    return 0;
}