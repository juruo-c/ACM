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

const int N = 100005, mod = 1000000007;

int n;
PII a[N];
int ans[N];

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
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i].first), a[i].second = i;
        sort(a + 1, a + 1 + n);

        bool flag = false;
        for (int i = 2; i <= n; i ++ )
            if (a[i].first != a[1].first)
            {
                flag = true;
                break;
            }

        if (!flag)
        {
            puts("NO");
            continue;
        }

        for (int i = 1; i <= n; i ++ )
        {
            ans[a[i].second] = n - i + 1;
        }

        for (int i = 1; i <= n; i ++ )
        {
            if (ans[a[i].second] == a[i].first)
            {
                if (a[1].first == a[i].first)
                {
                    swap(ans[a[i].second], ans[a[n].second]);
                }
                else 
                {
                    swap(ans[a[i].second], ans[a[1].second]);
                }
            }
        }

        puts("YES");
        for (int i = 1; i <= n; i ++ )
        {
            if (i > 1) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");

    }
    return 0;
}
