#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 4005;

int n, a[4];
int f[4][N];
bool g[4][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 3; i ++ ) scanf("%d", &a[i]);

	g[0][0] = g[1][0] = g[2][0] = true;
	for (int i = 1; i <= 3; i ++ )
		for (int j = 1; j <= n; j ++ )
		{
			f[i][j] = f[i - 1][j];
			for (int k = 1; k <= j / a[i]; k ++ )
				if (g[i - 1][j - k * a[i]])
					f[i][j] = max(f[i][j], f[i - 1][j - k * a[i]] + k);
			if (f[i][j]) g[i][j] = true;
		}

	// for (int i = 1; i <= 3; i ++ )
	// {
	// 	for (int j = 1; j <= n; j ++ )
	// 		printf("%d ", f[i][j]);
	// 	puts("");
	// }

	printf("%d\n", f[3][n]);

	return 0;
}