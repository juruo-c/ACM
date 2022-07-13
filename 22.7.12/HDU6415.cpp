#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 85;

int n, m, mod;
int f[2][N][N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d%d", &n, &m, &mod);
		memset(f[1], 0, sizeof f[1]);
		f[1][1][1] = n * m % mod;
		for (int i = 1; i <= n * m; i ++ )
		{
			memset(f[i + 1 & 1], 0, sizeof f[i + 1 & 1]);
			for (int j = 1; j <= n; j ++ )
				for (int k = 1; k <= m; k ++ )
				{
					if (f[i & 1][j][k])
					{
						f[i + 1 & 1][j + 1][k] = (f[i + 1 & 1][j + 1][k] + 1LL * f[i & 1][j][k] * k * (n - j) % mod) % mod;
						f[i + 1 & 1][j][k + 1] = (f[i + 1 & 1][j][k + 1] + 1LL * f[i & 1][j][k] * j * (m - k) % mod) % mod;
						f[i + 1 & 1][j][k] = (f[i + 1 & 1][j][k] + 1LL * f[i & 1][j][k] * (j * k - i) % mod) % mod;
					}
				}
		}

		printf("%d\n", f[n * m & 1][n][m]);

	}
	return 0;
}