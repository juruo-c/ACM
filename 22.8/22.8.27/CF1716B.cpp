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
        int n;scanf("%d", &n);
        printf("%d\n", n);
        for (int i = 1; i <= n; i ++ )
        {
            printf("%d ", i);
            for (int j = 1; j < i; j ++ )
                printf("%d ", j);
            for (int j = i + 1; j <= n; j ++ )
                printf("%d ", j);
            puts("");
        }
    }
    return 0;
}
