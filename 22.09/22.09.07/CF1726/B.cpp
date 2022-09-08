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
        int n, m;
        scanf("%d%d", &n, &m);
        if (m < n)
        {
            puts("No");
            continue;
        }
        bool flag = false;
        for (int i = 0; i < n; i += 2)
            if ((m - i) % (n - i) == 0)
            {
                printf("Yes\n");
                for (int j = 1; j <= i; j ++ )
                    printf("1 ");
                for (int j = i + 1; j <= n; j ++ )
                    printf("%d ", (m - i) / (n - i));
                puts("");
                flag = true;
                break;
            }
        if (!flag) puts("No");
    }
    return 0;
}
