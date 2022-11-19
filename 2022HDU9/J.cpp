#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

const int N = 505;

int n;
int a[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 1; i <= n; i ++ )
            ans = (((ans + a[i]) % mod) + 1LL * ans * a[i] % mod) % mod;
        printf("%d\n", ans);
    }
    return 0;
}