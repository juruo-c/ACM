#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int mod = 1000000007;

int n, k;

int qpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    cin >> n >> k;
    if (k >= n) printf("%d\n", qpow(2, n));
    else printf("%d\n", ((qpow(2, n) - qpow(2, n - k) + mod) % mod + 1) % mod);

    return 0;
}
