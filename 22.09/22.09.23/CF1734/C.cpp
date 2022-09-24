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

const int N = 1000005;

int n;
char t[N];
bool vis[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        memset(vis, false, sizeof vis);

        scanf("%d", &n);
        scanf("%s", t + 1);
        LL ans = 0;
        
        for (int i = 1; i <= n; i ++ )
            if (t[i] != '1')
            {
                int cnt = 0;
                for (int j = i; j <= n; j += i)
                {
                    if (t[j] == '1') break;
                    if (!vis[j])
                    {
                        vis[j] = true;
                        cnt ++;
                    }
                }
                ans += 1LL * cnt * i;
            }

        printf("%lld\n", ans);
    }
    return 0;
}
