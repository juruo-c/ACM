#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int a[N];

bool solve(int n, int m)
{
    
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t --)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        bool flag = false;
        for (int i = 1; i <= k; i ++ )
            scanf("%d", &a[i]);

        if (solve(n, m) || solve(m, n))
            puts("YES");
        else
            puts("NO");
        
    }
    return 0;
}
