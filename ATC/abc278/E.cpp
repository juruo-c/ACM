#include <iostream>

using namespace std;

const int N = 305;

int H, W, n, h, w;
int a[N][N];
int s[N][N][N];
int col[N];

int main()
{
    scanf("%d%d%d%d%d", &H, &W, &n, &h, &w);
    for (int i = 1; i <= H; i ++ )
        for (int j = 1; j <= W; j ++ )
            scanf("%d", &a[i][j]), col[a[i][j]] ++;
    
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= H; i ++ )
            for (int j = 1; j <= W; j ++ )
                s[k][i][j] = s[k][i - 1][j] + s[k][i][j - 1] - s[k][i - 1][j - 1] + (a[i][j] == k);
    
    for (int i = 1; i <= H - h + 1; i ++ )
    {
        for (int j = 1; j <= W - w + 1; j ++ )
        {
            int x = i + h - 1, y = j + w - 1;
            for (int k = 1; k <= n; k ++ )
                col[k] -= s[k][x][y] - s[k][i - 1][y] - s[k][x][j - 1] + s[k][i - 1][j - 1];
            int ans = 0;
            for (int k = 1; k <= n; k ++ )
                if (col[k]) ans ++;
            for (int k = 1; k <= n; k ++ )
                col[k] += s[k][x][y] - s[k][i - 1][y] - s[k][x][j - 1] + s[k][i - 1][j - 1];
            printf("%d ", ans);
        }
        puts("");
    }
        
    return 0;
}