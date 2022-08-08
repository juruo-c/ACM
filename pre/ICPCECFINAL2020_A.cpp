#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1000005, M = 62, mod = 998244353;

int n;
char s[N];
LL cnt[N];
LL s1, s2;
int f[5][M][M];

int fun(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a'+ 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 36;
}

void add(int x)
{
    s1 ++;
    cnt[x] ++;
    s2 += 2 * cnt[x] - 1;
}

void del(int x)
{
    s1 --;
    s2 -= 2 * cnt[x] - 1;
    cnt[x] --;
}

LL query(int x, int y)
{
    return ((s1 - cnt[x] - cnt[y]) * (s1 - cnt[x] - cnt[y]) - (s2 - cnt[x] * cnt[x] - cnt[y] * cnt[y])) / 2 % mod;
}

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++ ) add(fun(s[i]));

    for (int i = 0; i < M; i ++ )
        for (int j = 0; j < M; j ++ )
            if (i != j) f[0][i][j] = 1;

    int ans = 0;
    for (int i = n; i >= 1; i -- )
    {
        int t = fun(s[i]);
        del(t);
        for (int j = 0; j < M; j ++ )
        {
            if (t == j) continue;
            f[1][j][t] += f[0][j][t];
            if (f[1][j][t] >= mod) f[1][j][t] -= mod;
            f[3][j][t] += f[2][j][t];
            if (f[3][j][t] >= mod) f[3][j][t] -= mod;
            f[2][t][j] += f[1][t][j];
            if (f[2][t][j] >= mod) f[2][t][j] -= mod;
            ans = (ans + f[3][t][j] * query(j, t)) % mod;
        }
    }

    printf("%d\n", ans);

    return 0;
}
