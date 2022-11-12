#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 1e5 + 10;

int cnt[N];
int ksm(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }return ans;
}

int fact[N], inv[N];
int invNum[N];

void pre()
{
    fact[0] = 1;
    for(int i = 1; i < N; i ++) fact[i] = 1ll * i * fact[i - 1] % mod;
    inv[N - 1] = ksm(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i --) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

int C(int n, int m)
{
    return 1LL * fact[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
    pre();
    int n, m;
    scanf("%d%d", &n, &m);
    int mx = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int a;
        scanf("%d", &a);
        mx = max(a, mx);
        cnt[a] ++;
    }
    vector<int> A;
    for (int i = 0; i < N; i ++ )
        if (cnt[i]) A.push_back(i);
    for (int i = 1; i < N; i ++ )
        invNum[i] = ksm(i, mod - 2);

    if (mx > m)
    {
        for (int i = 1; i <= m; i ++ )
            puts("0");
        return 0;
    }

    for (int i = 1; i < mx; i ++ )  
        puts("0");
    
    int ans = 1;
    for (auto a : A)
        ans = 1LL * ans * ksm(C(mx, a), cnt[a]) % mod;
    printf("%d\n", ans);

    for (int k = mx + 1; k <= m; k ++ )
    {
        ans = 1LL * ans * ksm(k, n) % mod;
        for (auto a : A)
            ans = 1LL * ans * ksm(invNum[k - a], cnt[a]) % mod;
        printf("%d\n", ans);
    }

    return 0;
}