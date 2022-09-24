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
        
        puts("1");
        for (int i = 2; i <= n; i ++ )
        {
            printf("%d ", 1);
            for (int j = 2; j < i; j ++ )
                printf("%d ", 0);
            printf("%d\n", 1);
        }
    }
    return 0;
}
