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

const int N = 5005;

int n, x, y;
LL f[N][N]; //f[i][j] 表示第i个不好的位置到第j个不好的位置中的所有不好位置都变好的最少花费
char s[N], t[N];
int pos[N], cnt;

LL calc(int l, int r)
{
    int len = pos[r] - pos[l];
    if (len == 1)
        return min(x, y * 2);
    else return min(1LL * x * len, 1LL * y);
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
        scanf("%d%d%d", &n, &x, &y);
        scanf("%s%s", s + 1, t + 1);

        cnt = 0;
        for (int i = 1; i <= n; i ++ )
            if (s[i] != t[i])
                pos[++ cnt] = i;

        if (cnt % 2)
        {
            puts("-1");
            continue;
        }

        for (int i = 1; i < cnt; i ++ )
            f[i][i + 1] = calc(i, i + 1);

        for (int i = 4; i <= cnt; i += 2)
            for (int l = 1; l + i - 1 <= cnt; l ++ )
            {
                int r = l + i - 1;
                f[l][r] = min(f[l + 1][r - 1] + calc(l, r), f[l][r - 2] + calc(r - 1, r));
                f[l][r] = min(f[l][r], f[l + 2][r] + calc(l, l + 1));
                f[l][r] = min(f[l][r], 1LL * cnt / 2 * y);
            }

        printf("%lld\n", f[1][cnt]);
        
    }

    return 0;
}
