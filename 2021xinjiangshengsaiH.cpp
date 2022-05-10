#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 50005, M = 32, mod = 1000000007;

int n;
int a[N];
int f[M][M][2][2];
int pow2[2 * M];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	pow2[0] = 1;
	for (int i = 1; i < 2 * M; i ++ ) pow2[i] = 1LL * pow2[i - 1] * 2 % mod;

	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j <= 31; j ++ )
			for (int k = 0; k <= 31; k ++ )
				f[j][k][a[i] >> j & 1][a[i] >> k & 1] ++;

	int ans = 0;
	for (int i = 0; i <= 31; i ++ )
		for (int j = 0; j <= 31; j ++ )
			for (int k = 0; k <= 1; k ++ )
				for (int p = 0; p <= 1; p ++ )
					ans = (ans + 1LL * f[i][j][k][p] * f[i][j][k ^ 1][p ^ 1] % mod * pow2[i + j] % mod) % mod;
	
	printf("%d\n", ans);

	return 0;
}