#include <iostream>

using namespace std;

const int N = 60, mod = 998244353;

int n, m, K;
int f[N][N * N];
int g[N][N * N];

int main()
{
	cin >> n >> m >> K;
	for (int i = 1; i <= min(m, K); i ++ )
		f[1][i] = 1;

	for (int i = 1; i < n; i ++ )
		for (int j = i; j <= min(K, i * m); j ++ )
			for (int k = 1; k <= m; k ++ )
				f[i + 1][j + k] = (f[i + 1][j + k] + f[i][j]) % mod;

	int ans = 0;
	for (int i = n; i <= K; i ++ )
		ans = (ans + f[n][i]) % mod;

	cout << ans << endl;
	return 0;
}