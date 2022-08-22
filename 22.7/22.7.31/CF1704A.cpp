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

const int N = 55, mod = 1000000007;

int n, m;
char a[N], b[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &m);
        scanf("%s%s", a + 1, b + 1);

        bool flag = true;
        int j = n;
        for (int i = m; i >= 2; i --, j -- )
            if (b[i] != a[j])
            {
                flag = false;
                break;
            }

        if (!flag)
        {
            puts("NO");
            continue;
        }

        for (; j >= 1; j --)
            if (b[1] == a[j])
            {
                puts("YES");
                flag = false;
                break;
            }

        if (flag)
        {
            puts("NO");
        }

    }
    return 0;
}
