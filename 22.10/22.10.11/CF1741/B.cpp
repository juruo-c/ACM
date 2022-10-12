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
        int n;
        scanf("%d", &n);
        if (n == 3)
            puts("-1");
        else 
        {
            for (int i = 1, j = n; i <= n / 2; i ++ , j -- )
                printf("%d ", j);
            for (int i = n / 2 + 1, j = 1; i <= n; i ++, j ++)
                printf("%d ", j);
            puts("");
        }   
    }
    return 0;
}
