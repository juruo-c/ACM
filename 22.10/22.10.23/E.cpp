#include <iostream>
#include <algorithm>
#include <cstring>
#define ZYCMH

using namespace std;

typedef long long LL;

const int N = 200005, mod = 998244353;

int n;
int a[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if ( b & 1 ) res =  1LL * res * a % mod;
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

    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        
        int c0 = 0;
        for (int i = 1; i <= n; i ++ )
            if (a[i] == 0) c0 ++;

        int cnt = 0;
        for (int i = 1; i <= n; i ++ )
            if (a[i] == 1 && i <= c0) cnt ++;

        int t = 1LL * n * (n - 1) / 2 % mod;
        int ans = 0;
        for (int i = 1; i <= cnt; i ++ )
            ans = (ans + 1LL * t * qpow(i, mod - 2) % mod * qpow(i, mod - 2) % mod) % mod;
        printf("%d\n", ans);
    }


    return 0;
}