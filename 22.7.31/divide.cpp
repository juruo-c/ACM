#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        LL n, m;
        LL ans = 0;
        for (LL l = 1, r; l <= n; l = r + 1)
        {
            r = n / (n / l);
            ans += (n / l) * (r - l + 1);
        }
        for (LL l = 1, r; l <= min(n, m); l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ans += (n / l) * (m / l) * (r - l + 1);
        }
    }
    return 0;
}
