#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int mod = 1000000007;

int n;
char s[N];

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
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        int c1 = 0, c0 = 0;
        int ans = 0;
        for (int i = n; i >= 1; i -- )
        {
            if (s[i] == '1')
                ans = (ans + 1LL * qpow(2, c0) * qpow(3, c1) % mod) % mod;
            if (s[i] == '1') c1 ++;
            else c0 ++;
        }

        printf("%d\n", (ans + 1) % mod);
    }
    return 0;
}