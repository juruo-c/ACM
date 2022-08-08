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

int n, m;
bool f[N][N];
char s[N][N];

bool solve(char c)
{
    for (int i = n; i >= 1; i -- )
        for (int j = m; j >= 1; j -- )
        {
            if (s[i][j] != '.') 
            {
                f[i][j] = (s[i][j] == c);
                continue;
            }
            f[i][j] = false;
            if ((i + j) % 2)
            {
                if (i == n) f[i][j] = f[i][j + 1];
                else if(j == m) f[i][j] = f[i + 1][j];
                else f[i][j] = f[i + 1][j] & f[i][j + 1];
            }
            else 
            {
                if (i == n) f[i][j] = f[i][j + 1];
                else if(j == m) f[i][j] = f[i + 1][j];
                else f[i][j] = f[i + 1][j] | f[i][j + 1];    
            }
        }

    return f[1][1];
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
        scanf("%d%d", &n, &m);
        memset(f, false, sizeof f);
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%s", s[i] + 1);
        }

        if (s[n][m] == '.') s[n][m] = 'C';
        
        if (solve('A')) printf("yes"), putchar(' ');
        else printf("no"), putchar(' ');
        if (solve('C')) printf("yes"), putchar(' ');
        else printf("no"), putchar(' ');
        if (solve('B')) printf("yes"), puts("");
        else printf("no"), puts("");
    }
    return 0;
}
