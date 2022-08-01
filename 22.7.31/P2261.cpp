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
    int n, k;
    cin >> n >> k;
    LL ans = 1LL * n * k;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        if (k / l) r = min(n, k / (k / l));
        else r = n;
        ans -= 1LL * (r - l + 1) * (l + r) / 2 * (k / l);
    }
    cout << ans << endl;
    return 0;
}
