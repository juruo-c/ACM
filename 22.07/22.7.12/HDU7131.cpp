#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005, mod = 998244353;

int n;
char s[N];
char ts[] = " nunhehheh";
int f[N][10];
int sum[N];

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	int t;scanf("%d", &t);
	while (t -- )
	{
		scanf("%s", s + 1);
		memset(f, 0, sizeof f);
		n = strlen(s + 1);
		int m = 0;
		for (int i = 1; i <= n; i ++ ) if (s[i] == 'a') m ++;

		for (int i = 0; i <= n; i ++ )
			f[i][0] = 1;

		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= 9; j ++ )
			{
				f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
				if (s[i] == ts[j]) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mod;
			}

		int last = 0;
		int ans = 0;
		for (int i = 1; i <= n; i ++ )
			if (s[i] == 'a')
			{
				ans = (ans + 1LL * (f[i][9] - last + mod) % mod * ((qpow(2, m) - 1 + mod) % mod) % mod) % mod;
				m --;
				last = f[i][9];
			}

		printf("%d\n", ans);

	}
	return 0;
}