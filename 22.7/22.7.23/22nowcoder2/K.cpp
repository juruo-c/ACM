#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 205, mod = 1000000007;

int n, m;
char s[N]; 
int f[N][N][N];

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d%d%s", &n, &m, s + 1);
        memset(f, 0, sizeof f);
        f[0][0][0] = 1;
        for (int i = 0; i < m; i ++ )
            for (int j = 0; j <= n; j ++ )
                for (int k = 0; k <= m / 2; k ++ )
                    if (f[i][j][k])
                    {
                        int t = f[i][j][k];
                        if (k)
                        {
                            if (s[j + 1] == ')')
                                f[i + 1][j + 1][k - 1] = (f[i + 1][j + 1][k - 1] + t) % mod;
                            else f[i + 1][j][k - 1] = (f[i + 1][j][k - 1] + t) % mod;
                        }
                        if (s[j + 1] == '(') f[i + 1][j + 1][k + 1] = (f[i + 1][j + 1][k + 1] + t) % mod;
                        else f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + t) % mod;
                    }  

        printf("%d\n", f[m][n][0]);

    }
    return 0;
}