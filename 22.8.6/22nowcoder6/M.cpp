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

const int N = 505, mod = 1000000007;

int f[N][N][3], g[N][N][3];
/*
0: win 
1: draw
2: lose
*/
char s[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int n, m;
        memset(f, -1, sizeof f);
        memset(g, -1, sizeof g);
        scanf("%d%d", &n, &m);

        for (int i = 0; i < 3; i ++ )    
            f[n][m][i] = g[n][m][i] = 1;
        
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%s", s + 1);
            for (int j = 1; j <= m; j ++ )
            {
                if (s[j] == 'A')
                    for (int k = 0; k < 3; k ++ )
                        f[i][j][k] = 0, g[i][j][k] = 2;
                else if (s[j] == 'B')
                {
                    for (int k = 0; k < 3; k ++ )
                        f[i][j][k] = 2, g[i][j][k] = 0;
                }
            }
        }
        
        for (int i = n; i >= 1; i -- )
            for (int j = m; j >= 1; j -- )
            {
                if (i == n && j == m) continue;
                if ((i + j) % 2)
                {
                    if (g[i][j][0] == -1)
                    {
                        if (f[i + 1][j][0] == 2 || f[i][j + 1][0] == 2) g[i][j][0] = 0;
                        else if (f[i + 1][j][0] == 1 || f[i][j + 1][0] == 1) g[i][j][0] = 1;
                        else g[i][j][0] = 2;
                    }
                    if (g[i][j][1] == -1)
                    {
                        if (f[i + 1][j][1] == 1 && f[i][j + 1][1] == 1) g[i][j][1] = 1;
                        else 
                        {
                            if (f[i + 1][j][1] == 1 && f[i][j + 1][1] == -1) g[i][j][1] = 1;
                            else if(f[i + 1][j][1] == -1 && f[i][j + 1][1] == 1) g[i][j][1] = 1;
                            else
                            {
                                if (f[i + 1][j][1] != -1) g[i][j][1] = f[i + 1][j][1];
                                else g[i][j][1] = f[i][j + 1][1];
                            }
                        }
                    }
                    if (g[i][j][2] == -1)
                    {
                        if (f[i + 1][j][2] == 0 || f[i][j + 1][2] == 0) g[i][j][2] = 2;
                        else if(f[i + 1][j][2] == 1 || f[i][j + 1][2] == 1) g[i][j][2] = 1;
                        else g[i][j][2] = 0;
                    }
                }
                else
                {
                    if (f[i][j][0] == -1)
                    {
                        if (g[i + 1][j][0] == 2 || g[i][j + 1][0] == 2) f[i][j][0] = 0;
                        else if(g[i + 1][j][0] == 1 || g[i][j + 1][0] == 1) f[i][j][0] = 1;
                        else f[i][j][0] = 2;
                    }
                    if (f[i][j][1] == -1)
                    {
                        if (g[i + 1][j][1] == 1 || g[i][j + 1][1] == 1) f[i][j][1] = 1;
                        else 
                        {
                            if (g[i + 1][j][1] != -1) f[i][j][1] = g[i + 1][j][1];
                            else f[i][j][1] = g[i][j + 1][1];
                        }
                    }
                    if (f[i][j][2] == -1)
                    {
                        if (g[i + 1][j][2] == 0 || g[i][j + 1][2] == 0) f[i][j][2] = 2;
                        else if(g[i + 1][j][2] == 1 || g[i][j + 1][2] == 1) f[i][j][2] = 1;
                        else f[i][j][2] = 0;
                    }
                }
            }

        if (f[1][1][0] == 0) printf("yes");
        else printf("no");
        if (f[1][1][1] == 1) printf(" yes");
        else printf(" no");
        if (f[1][1][2] == 2) printf(" yes");
        else printf(" no");
        puts("");
    }
    return 0;
}
