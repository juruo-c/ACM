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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        int u = sx - d, dd = sx + d, l = sy - d, r = sy + d;
        // cout << u << " " << dd << " " << l << " " << r << endl;
        if ((l > 1 && dd < n) || (r < m && u > 1)) cout << n + m - 2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}
