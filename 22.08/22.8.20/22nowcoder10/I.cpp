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

int n, m;
int a[N], b[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i ++ )
        scanf("%d", &b[i]);
    
    map<int, PII> mp;
    bool flag = false;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            PII t = make_pair(i, j);
            if (mp.find(a[i] + b[j]) != mp.end())
            {
                PII tt = mp[a[i] + b[j]];
                if (t.first != tt.first && t.second != tt.second)
                {
                    printf("%d %d %d %d\n", t.first, tt.first, t.second, tt.second);
                    flag = true;
                    break;
                }
            }
            mp[a[i] + b[j]] = t;
        }
        if (flag) break;
    }

    if (!flag) puts("-1");
    return 0;
}
