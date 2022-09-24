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
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        int b;
        scanf("%d", &b);
        for (int j = 1; j <= n; j ++ )
            printf("%d ", (b - (i - j) * (i - 1) % n + n) % n);
        puts("");
    }
    return 0;
}
