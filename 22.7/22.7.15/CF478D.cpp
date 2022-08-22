#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005, M = 900, mod = 1000000007;

int r, g;
int f[2][N];

int main()
{
	scanf("%d%d", &r, &g);
	int h = 0;
	f[0][0] = 1;
	for (int i = 1; i < M; i ++ )
	{
		memset(f[i & 1], 0, sizeof f[i & 1]);
		bool flag = false;
		for (int j = 0; j <= r; j ++ )
		{
			if (1LL * i * (i + 1) / 2 - j > g) continue;
			f[i & 1][j] = (f[i & 1][j] + f[i - 1 & 1][j]) % mod;
			if (j >= i) f[i & 1][j] = (f[i & 1][j] + f[i - 1 & 1][j - i]) % mod;
			if (f[i & 1][j]) flag = true;
		}
		if (flag) h = i;
		else break;
	}

	// cout << h << endl;

	int ans = 0;
	for (int i = 0; i <= r; i ++ )
		if (1LL * h * (h + 1) / 2 - i <= g) 
			ans = (ans + f[h & 1][i]) % mod;

	printf("%d\n", ans);

	return 0;
}