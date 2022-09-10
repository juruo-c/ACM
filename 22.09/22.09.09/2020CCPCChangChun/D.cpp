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

const int N = 3005, mod = 1000000007;

int c;
char s[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * a * res % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%s%d", s + 1, &c);
    int ans = 1;
    int n = strlen(s + 1);
    for (int i = n; i >= 1; i -- )
        if (s[i] == '1')
            ans = (qpow(1 + c, n - i) + 1LL * ans * c % mod) % mod;
    printf("%d\n", ans);
    return 0;
}
