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

const int N = 20;

int n, m, k;
int stx, sty, edx, edy;
struct Wall
{
    int x1, y1, x2, y2;
}walls[N];
bool wall[N][N][4]; 
bool vis[N][N];
int bits[1 << N];
/*0:左 1:右 2:上 3:下*/
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void add_wall(int bit)
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            for (int k = 0; k < 4; k ++ )
                wall[i][j][k] = false;

    for (int i = 0; i < k; i ++ )
        if (!(bit >> i & 1))
        {
            // cout << i << endl;
            int x1 = walls[i].x1, y1 = walls[i].y1;
            int x2 = walls[i].x2, y2 = walls[i].y2;
            if (x1 == x2)
            {
                // cout << "x1 = " << x1 << endl;
                for (int j = y1; j < y2; j ++ )
                {
                    if (x1 > 0) wall[x1 - 1][j][1] = true;
                    if (x1 < n) wall[x1][j][0] = true; 
                }
            }
            else if (y1 == y2)
            {
                // cout << "y1 = " << y1 << endl;
                for (int j = x1; j < x2; j ++ )
                {
                    if (y1 > 0) wall[j][y1 - 1][2] = true;
                    if (y1 < m) wall[j][y1][3] = true;
                }
            }
        }
}

bool dfs(int x, int y)
{
    // cout << x << " " << y << endl;
    if (x == edx && y == edy)
        return true;
    vis[x][y] = true;
    for (int i = 0; i < 4; i ++ )
    {
        if (wall[x][y][i]) continue;
        int tx = x + dx[i], ty = y + dy[i];
        if (vis[tx][ty] || tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
        if (dfs(tx, ty)) return true;
    }   
    return false;
}

bool check()
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            vis[i][j] = false;
    return dfs(stx, sty);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    for (int i = 0; i < (1 << 15); i ++ )
        for (int j = 0; j < 15; j ++ )
            if (i >> j & 1) bits[i] ++;
    
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d%d", &n, &m, &k);    
        scanf("%d%d%d%d", &stx, &sty, &edx, &edy);
        for (int i = 0; i < k; i ++ )
        {
            scanf("%d%d%d%d", &walls[i].x1, &walls[i].y1, &walls[i].x2, &walls[i].y2);
            if (walls[i].x1 > walls[i].x2) swap(walls[i].x1, walls[i].x2);
            if (walls[i].y1 > walls[i].y2) swap(walls[i].y1, walls[i].y2);
        }

        int ans = k + 1;
        for (int i = 0; i < (1 << k); i ++ )
        {
            // cout << "i = " << i << endl;
            add_wall(i);
            if (check())
            {
                // cout << "i = " << i << " bit = " << bits[i] << endl;
                ans = min(ans, bits[i]);
            }
        }

        printf("%d\n", ans);

    }
    return 0;
}
