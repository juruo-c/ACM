#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 4005;

int n;
char a[N][N];
int sum[N][N];
int p[N][N];

int main()
{
	int t; scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%s", a[i] + 1);
			for (int j = 1; j <= n; j ++ )
				a[i + n][j] = a[i][j + n] = a[i + n][j + n] = a[i][j];
		}
		int m = n << 1;
		for (int i = 1; i <= m; i ++ )
			for (int j = 1; j <= m; j ++ )
			{
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j] - '0';
				p[i][j] = p[i - 1][j - 1] + a[i][j] - '0';
			}

		int ans = n * n;
		for (int i = 1; i + n - 1 <= m; i ++ )
			for (int j = 1; j + n - 1 <= m; j ++ )
			{
				int x = i + n - 1, y = j + n - 1;
				int t = p[x][y] - p[i - 1][j - 1];
				ans = min(ans, sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] - t + n - t);
			}

		printf("%d\n", ans);
	}
	return 0;
}