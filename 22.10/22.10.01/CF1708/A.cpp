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
        int n;
        scanf("%d", &n);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        bool flag = true;
        for (int i = 2; i <= n; i ++ )
        {
            if (a[i] % a[1])
            {
                flag = false;
                break;
            }
        }

        if (flag) puts("YES");
        else puts("NO");

    }
    return 0;
}
