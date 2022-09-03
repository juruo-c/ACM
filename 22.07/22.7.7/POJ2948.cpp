#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 505;

int n, m;
int y[N][N], b[N][N];
int f[N][N];
int sum[N];

int main()
{
	while (~scanf("%d%d", &n, &m) && (n || m))
	{
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				scanf("%d", &y[i][j]);
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				scanf("%d", &b[i][j]);

		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				y[i][j] += y[i][j - 1];

		for (int j = 1; j <= m; j ++ )
			for (int i = 1; i <= n; i ++ )
				b[i][j] += b[i - 1][j];

		memset(f, 0, sizeof f);

		for (int i = 1; i <= m; i ++ ) sum[i] = sum[i - 1] + b[1][i];
		for (int i = 1; i <= m; i ++ )
			for (int j = 0; j <= i; j ++ )
				f[1][i] = max(f[1][i], y[1][j] + sum[i] - sum[j]);

		for (int i = 1; i <= n; i ++ ) sum[i] = sum[i - 1] + y[i][1];
		for (int i = 1; i <= n; i ++ )
			for (int j = 0; j <= i; j ++ )
				f[i][1] = max(f[i][1], b[j][1] + sum[i] - sum[j]);

		for (int i = 2; i <= n; i ++ )
			for (int j = 2; j <= m; j ++ )
				f[i][j] = max(f[i][j - 1] + b[i][j], f[i - 1][j] + y[i][j]);

		printf("%d\n", f[n][m]);
	}

	return 0;
}