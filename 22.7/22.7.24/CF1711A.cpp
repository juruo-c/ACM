#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        printf("%d", n);
        for (int i = 1; i < n; i ++ )
            printf(" %d", i);
        puts("");
    }
    return 0;
}
