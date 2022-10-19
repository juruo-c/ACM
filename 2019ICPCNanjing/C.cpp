#include<bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int a[N][N];
int dp[N][N][5];
int n, m;
bool is_max(int x, int y)
{
    for(int i = 0; i < 4; i ++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if(a[nx][ny] == a[x][y] + 1) return false;
    }
    return true;
}
void dfs(int x, int y)
{
    if(dp[x][y][1] != -1) return;
    dp[x][y][1] = 1;
    dp[x][y][2] = dp[x][y][3] = dp[x][y][4] = 0;
    for(int i = 0; i < 4; i ++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if(a[nx][ny] == a[x][y] - 1)
        {
            dfs(nx, ny);
            if(dp[nx][ny][4] > 0) dp[x][y][4] = (dp[x][y][4] + dp[nx][ny][4]) % mod;
            for(int j = 4; j >= 2; j --)
            {
                if(dp[nx][ny][j - 1] > 0) 
                    dp[x][y][j] = (dp[x][y][j] + dp[nx][ny][j - 1]) % mod;
            } 
            
        }
    }
    if (dp[x][y][2] > 0 || dp[x][y][3] > 0 || dp[x][y][4] > 0) dp[x][y][1] = 0;
    // for(int i = 1; i <= 4; i ++) cout << x << ' ' << y << ' ' << a[x][y] << ' ' << i << ' ' << ' ' << dp[x][y][i] << endl;
}
int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(dp[i][j][1] == -1) dfs(i, j);
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(is_max(i, j) && dp[i][j][4] > 0) ans = (ans + dp[i][j][4]) % mod;
        }
    }
    printf("%d\n", ans);
    return 0;
}
