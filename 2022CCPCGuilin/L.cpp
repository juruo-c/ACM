#include <iostream>

using namespace std;

int a[15][15];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int t = m;

    for (int i = 1; i <= n; i += 2)
    {
        a[i][t] = 1;
        a[i + 1][t] = 1;
        if (t > 1) t --;
    }

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
            printf("%d ", a[i][j]);
        puts("");
    }

    return 0;
}