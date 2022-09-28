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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n, c;
        scanf("%d%d", &n, &c);
        vector<int> cnt(105, 0);
        for (int i = 1; i <= n; i ++ )
        {
            int a;
            scanf("%d", &a);
            cnt[a] ++;
        }

        int ans = 0;
        for (int i = 1; i <= 100; i ++ )
        {
            if (cnt[i] >= c) ans += c;
            else ans += cnt[i];
        }
        printf("%d\n", ans);

    }
    return 0;
}
