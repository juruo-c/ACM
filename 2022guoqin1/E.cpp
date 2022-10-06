#include <iostream>
#include <algorithm>
#include <cstring>
#define ZYCMH

using namespace std;

const int N = 100005, INF = 0x3f3f3f3f;

int n, m;
char S[N], F[105];
int f[105][N];
int mx[N][36];

int get(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    else return c - 'a' + 10;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%s", S + 1);
        scanf("%s", F + 1);
        n = strlen(S + 1);
        m = strlen(F + 1);

        for (int j = 1; j <= n; j ++ ) 
        {
            for (int i = 0; i < 36; i ++ )
                mx[j][i] = mx[j - 1][i];
            mx[j][get(S[j])] = j;
        }

        for (int i = 1; i <= m; i ++ )
            for (int j = 1; j <= n; j ++ )
                f[i][j] = -1;

        for (int i = 1; i <= n; i ++ )
            if (S[i] == F[1])
                f[1][i] = i;
        
        for (int i = 2; i <= m; i ++ )
            for (int j = 1; j <= n; j ++ )  
                if (S[j] == F[i] && mx[j - 1][get(F[i - 1])])
                    f[i][j] = f[i - 1][mx[j - 1][get(F[i - 1])]];

        int pos = 0, ans = n + 1;
        for (int i = 1; i <= n; i ++ )
            if (S[i] == F[m] && f[m][i] != -1)
            {
                int len = i - f[m][i] + 1;
                if (len < ans)
                    ans = len, pos = i;
            }

        // printf("pos = %d ans = %d\n", pos, ans);
        for (int i = pos - ans + 1; i <= pos; i ++ )
            printf("%c", S[i]);
        puts("");
    }
    return 0;
}