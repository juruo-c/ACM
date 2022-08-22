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

const int N = 400005;

vector<int> factor[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    for (int i = 1; i < N; i ++ )
        for (int j = i; j < N; j += i)
            factor[j].push_back(i);

    int t; scanf("%d", &t);
    while (t --)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        LL ans = 1LL * (r - l + 1) * (r - l) * (r - l - 1) / 6;
        for (int k = l + 2; k <= r; k ++ )
        {
            for (int j = 0; j < factor[k * 2].size() && factor[2 * k][j] < k; j ++ )
            {
                int t1 = factor[k * 2][j];
                if (t1 < l) continue;
                for (int i = 0; i < factor[k * 2].size() && factor[2 * k][i] < t1; i ++ )
                {
                    int t2 = factor[k * 2][i];
                    if (t2 < l) continue;
                    if (k % t1 || k % t2) ans -= (t1 + t2 > k);
                    else ans --;
                }
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
