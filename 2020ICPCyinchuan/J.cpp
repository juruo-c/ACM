#include <iostream>

using namespace std;

const int N = 1005;

int m;
int n[N * N], s[N * N], w[N * N], e[N * N];
int ans[N][N];

int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= m * m; i ++ )
    {
        scanf("%d%d%d%d", &n[i], &s[i], &w[i], &e[i]);
        if (n[i] == -1 && w[i] == -1) ans[1][1] = i;
        if (n[i] == -1 && e[i] == -1) ans[1][m] = i;
        if (s[i] == -1 && w[i] == -1) ans[m][1] = i;
        if (s[i] == -1 && e[i] == -1) ans[m][m] = i;
    }
    
    for (int i = 1; i <= m - 2; i ++ )
        ans[i + 1][1] = s[ans[i][1]], ans[i + 1][m] = s[ans[i][m]];

    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= m - 2; j ++ )
            ans[i][j + 1] = e[ans[i][j]];

    for (int i = 1; i <= m; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            if (j > 1) printf(" ");
            printf("%d", ans[i][j]);
        }
        puts("");
    }

    return 0;
}