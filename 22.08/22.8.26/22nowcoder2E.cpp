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

int Lim;
int L, R[N];
LL revF[N], Exp[N];
int jc[N], jc_inv[N];

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
                int x = a[pos + k], y = w * a[pos + k + mid] % p;
                a[pos + k] = (x + y) % p;
                a[pos + k + mid] = (x - y + p) % p;
            }
        }
    }

    if (type == -1)
    {
        LL inv = qpow(Lim, p - 2);
        for (int i = 0; i < Lim; i ++ )
            a[i] = a[i] * inv % p;
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

int C(int n, int m)
{
    return 1LL * jc[n] * jc_inv[m] % p * jc_inv[n - m] % p;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % p;
    jc_inv[n] = qpow(jc[n], p - 2);
    for (int i = n - 1; i >= 1; i -- )
        jc_inv[i] = 1LL * jc_inv[i + 1] * (i + 1) % p;

    for (int i = 0, j = n; i <= n; i ++, j -- ) 
        if (n - 3 * i >= 0)
            revF[j] = 1LL * C(n - 2 * i, i) * qpow(26, n - 3 * i) % p * jc[i] % p;

    for (int i = 0; i <= n; i ++ )
        if (i & 1)
            Exp[i] = (p - jc_inv[i]) % p;
        else Exp[i] = jc_inv[i];

    mul(revF, Exp, 2 * n);

    for (int i = n, j = 0; i >= 0; i --, j ++)
        printf("%lld ", revF[i] * jc_inv[j] % p);
    return 0;
}
