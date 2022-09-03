#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 505;

int n, k, r, c;
char ch[N][N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d%d%d", &n, &k, &r, &c);
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                ch[i][j] = '.';
        for (int i = c; i <= n; i += k)
            ch[r][i] = 'X';
        for (int i = c; i >= 1; i -= k)
            ch[r][i] = 'X';
        
        for (int i = r - 1; i >= 1; i -- )
            for (int j = 1; j <= n; j ++ )
                if (j == 1)
                    ch[i][j] = ch[i + 1][n];
                else ch[i][j] = ch[i + 1][j - 1];

        for (int i = r + 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                if (j == n)
                    ch[i][j] = ch[i - 1][1];
                else ch[i][j] = ch[i - 1][j + 1];
        
        for (int i = 1; i <= n;i ++ )
        {
            for (int j = 1; j <= n; j ++ )
                printf("%c", ch[i][j]);
            puts("");
        }

    }   
    return 0;
}
