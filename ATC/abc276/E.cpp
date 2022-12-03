#include <iostream>

using namespace std;

const int N = 200005;
const int mod = 998244353;

int n, p;
int f[N];

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

int main()
{
    cin >> n >> p;

    f[0] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        
        f[i] = 1LL * (100 - p) * (f[max(i - 1, 0)] + 1) % mod + 1LL * p * (f[max(i - 2, 0)] + 1) % mod;
        f[i] = 1LL * f[i] * qpow(100, mod - 2) % mod;
    }
    
    cout << f[n];

    return 0;
}