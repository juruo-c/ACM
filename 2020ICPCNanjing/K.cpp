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
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == 0) puts("-1");
    else 
    {

        for (int i = 1; i < k; i ++ )
            printf("%d ", i + 1);
        printf("1 ");
        for (int i = k + 1; i <= n; i ++ )
            printf("%d ", i);
        puts("");
    }
    return 0;
}
