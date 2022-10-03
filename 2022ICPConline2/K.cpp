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

const int N = 205, mod = 998244353;

int n;
bool cover[N][N]; //表示以(x,y)为左下角的格子是否被涂满
bool st[N][N][4]; //表示以(x,y)为左下角的格子是否存在四种圆弧
int inv4, inv6;

int qpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        b >>= 1;
        a = 1LL * a * a %mod;
    }
    return res;
}

void deal(int t, int x, int y)
{
    if (t == 1)
        cover[x][y] = cover[x][y - 1] = cover[x - 1][y] = cover[x - 1][y - 1] = true;
    else 
        st[x][y][0] = st[x - 1][y][1] = st[x - 1][y - 1][2] = st[x][y - 1][3] = true;
}

int solveRe()
{
    int res = 0;
    for (int i = 1; i <= 202; i ++ )
        for (int j = 1; j <= 202; j ++ )
        {
            if (!cover[i][j]) continue;
            if (!cover[i - 1][j] && !st[i][j][0] && !st[i][j][3])
                res = (res + 1) % mod;
            if (!cover[i][j + 1] && !st[i][j][2] && !st[i][j][3])
                res = (res + 1) % mod;
            if (!cover[i][j - 1] && !st[i][j][0] && !st[i][j][1])
                res = (res + 1) % mod;
            if (!cover[i + 1][j] && !st[i][j][1] && !st[i][j][2])
                res = (res + 1) % mod;
        }
    return res;
}

int solve(int cnt, int i, int j)
{   
    if (cnt == 1)
        return inv4;
    else if (cnt == 2)
    {
        int a = -1, b = -1;
        for (int k = 0; k < 4; k ++ )
            if (st[i][j][k])
            {
                if (a == -1) a = k;
                else b = k;
            }
        if ((a == 0 && b == 2) || (a == 1 && b == 3)) return 0;
        else return inv6; 
    }
    else return 0;
}

int solveCir()
{
    int res = 0;
    for (int i = 1; i <= 202; i ++ )
        for (int j = 1; j <= 202; j ++ )
        {
            if (cover[i][j]) continue;

            int cnt = st[i][j][0] + st[i][j][1] + st[i][j][2] + st[i][j][3];
            res = ( res + solve(cnt, i, j) ) % mod;
        }
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    inv4 = qpow(4, mod - 2);
    inv6 = qpow(6, mod - 2);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++ )
    {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        x += 102, y += 102;
        deal(type, x, y);
    }

    int a = solveRe();
    int b = solveCir();
    printf("%d %d\n", a, b * 2 % mod);
    
    return 0;
}
