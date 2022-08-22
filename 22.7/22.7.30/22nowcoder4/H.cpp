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

int n;
int mx[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        int area = n * (n + 1) * (n + 2) / 6;
        int h, w, res = 0x3f3f3f3f;
        for (int i = 1; i * i <= area; i ++ )
        {
            if (area % i == 0)
            {
                int th = i, tw = area / i;
                if (res > 2 * (th + tw))
                {
                    res = 2 * (th + tw);
                    h = th, w = tw;
                }
            }
        }

        if (h > w) swap(h, w);
        printf("%d\n", res);
        for (int i = 1; i <= h; i ++ ) mx[i] = 0;

        for (int len = n; len >= 1; len --)
            for (int i = 1; i <= n - len + 1; i ++)
                for (int j = 1; j <= h; j ++ )
                    if (w - mx[j] >= len)
                    {
                        printf("%d %d %d %d\n", mx[j], j - 1, mx[j] + len, j);
                        mx[j] += len;
                        break;
                    }

    }
    return 0;
}
