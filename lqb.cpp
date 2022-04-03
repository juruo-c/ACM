#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 21, M = 1 << 21;

int n = 21;
LL f[N][M];
bool g[N][N];

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			if (gcd(i, j) == 1) g[i - 1][j - 1] = true;

	f[0][1] = 1;
	for (int j = 1; j < 1 << n; j ++ )
		for (int i = 0; i < n; i ++ )
			if (f[i][j])
			{
				for (int k = 0; k < n; k ++ )
					if ((j >> k & 1) == 0 && g[i][k])
						f[k][j ^ ( 1 << k )] += f[i][j];
			}

	LL ans = 0;
	for (int i = 1; i < n; i ++ )
		ans += f[i][(1 << n) - 1];
	cout << ans << endl;

	return 0;
}