#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1005;

int n;
int a[N][N];
int fa[N * 2];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

void Union(int a, int b)
{
    a = getf(a), b = getf(b);
    fa[a] = b;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                scanf("%d", &a[i][j]);

        for (int i = 1; i <= 2 * n; i ++ ) fa[i] = i;
        
        for (int i = 1; i <= n; i ++ )
            for (int j = i + 1; j <= n; j ++ )
                if (a[i][j] > a[j][i])
                {
                    if (getf(i) == getf(j) || getf(i + n) == getf(j + n))
                        continue;
                    Union(i, j + n);
                    Union(i + n, j);
                }
                else if(a[i][j] < a[j][i])
                {
                    if (getf(i) == getf(j + n) || getf(i + n) == getf(j))
                        continue;
                    Union(i, j);
                    Union(i + n, j + n);
                }

        for (int i = 1; i <= n; i ++ )
        {
            if (getf(i) <= n)
            {
                for (int j = 1; j <= n; j ++ )
                    swap(a[i][j], a[j][i]);
            }
        }

        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 1; j <= n; j ++ )
            {
                if (j > 1) printf(" ");
                printf("%d", a[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
