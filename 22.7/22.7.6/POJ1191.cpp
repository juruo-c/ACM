#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 10;

double sum, miu;
int n, m = 8;
int a[N][N];
double f[N][N][N][N][20];

int getS(int i, int j, int x, int y)
{
	return a[x][y] - a[i - 1][y] - a[x][j - 1] + a[i - 1][j - 1];
}

double dfs(int i, int j, int x, int y, int k)
{
	int t = getS(i, j, x, y);
	if (k == 1) return f[i][j][x][y][k] = t * (t - 2 * miu);
	if (f[i][j][x][y][k]) return f[i][j][x][y][k];

	f[i][j][x][y][k] = 1e18;
	for (int bk = i; bk < x; bk ++ )
	{
		int tt = getS(bk + 1, j, x, y);
		f[i][j][x][y][k] = min(f[i][j][x][y][k], dfs(i, j, bk, y, k - 1) + tt * (tt - 2 * miu));
		f[i][j][x][y][k] = min(f[i][j][x][y][k], dfs(bk + 1, j, x, y, k - 1) + (t - tt) * (t - tt - 2 * miu));
	}

	for (int bk = j; bk < y; bk ++ )
	{
		int tt = getS(i, j, x, bk);
		f[i][j][x][y][k] = min(f[i][j][x][y][k], dfs(i, bk + 1, x, y, k - 1) + tt * (tt - 2 * miu));
		f[i][j][x][y][k] = min(f[i][j][x][y][k], dfs(i, j, x, bk, k - 1) + (t - tt) * (t - tt - 2 * miu));
	}

	return f[i][j][x][y][k];
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ ) 
		{
			scanf("%d", &a[i][j]);
			sum += a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	miu = sum / n;

	printf("%.3f\n", sqrt((dfs(1, 1, m, m, n) + sum * sum / n) / n));

	return 0;
}