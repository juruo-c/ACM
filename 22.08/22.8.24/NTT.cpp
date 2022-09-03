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

const int p = 998244353, g = 3;
const int N = 4000005;

LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int n, m;
int Lim, L;
int R[N];
LL a[N], b[N];


void NTT(LL* a, int type)
{
    for (int i = 0; i < Lim; i ++ )
        if (i < R[i])
            swap(a[i], a[R[i]]);
    
    for (int mid = 1; mid < Lim; mid <<= 1)
    {
        LL wn = qpow(g, (p - 1) / (mid * 2));
        if (type == -1) wn = qpow(wn, p - 2);
        for (int len = mid << 1, pos = 0; pos < Lim; pos += len)
        {
            LL w = 1;
            for (int k = 0; k < mid; k ++, w = (w * wn) % p)
            {
                int x = a[pos + k], y = w * a[pos + mid + k] % p;
                a[pos + k] = (x + y) % p;
                a[pos + k + mid] = (x - y + p) % p;
            }
        }
    }
    if (type == -1)
    {
        LL inv = qpow(Lim, p - 2);
        for (int i = 0; i < Lim; i ++ )
            a[i] = (a[i] * inv) % p;
    }
}

void mul(LL* a, LL* b, int deg)
{
    for (Lim = 1, L = 0; Lim <= deg; Lim <<= 1) L ++;
    for (int i = 0; i < Lim; i ++ )
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    NTT(a, 1);
    NTT(b, 1);
    for (int i = 0; i < Lim; i ++ ) 
        a[i] = a[i] * b[i] % p;
    NTT(a, -1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i ++ ) 
        scanf("%lld", &a[i]);
    for (int i = 0; i <= m; i ++ )
        scanf("%lld", &b[i]);
    
    mul(a, b, n + m);

    for (int i = 0; i <= n + m; i ++ )
        printf("%d ", a[i]);

    return 0;
}
