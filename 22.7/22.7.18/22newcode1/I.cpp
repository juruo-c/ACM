#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef long long LL;

const int N = 150, M = 20, mod = 1000000007;

LL f[10][N][M][M];
int x[] = {0, 1, 2, 3, 4, 5, 6};
int y[] = {13, 11, 9, 7, 5, 3, 1};
LL sum[10];

LL qpow(LL a, int b)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = 1LL * ans * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	int kase = 0;
	int n = 34 * 4 - 13; 
	
	for (int s = 0; s <= 6; s ++ )
	{
		f[s][0][x[s]][y[s]] = 1;
		for (int k = 0; k < n; k ++ )
			for (int i = 0; i <= 6; i ++ )
				for (int j = 1; j <= 13; j ++ )
					if (2 * i + j == 13 && f[s][k][i][j])
					{
						LL p = 1LL * j * 3 % mod * qpow(n - k, mod - 2) % mod;
						if (j >= 2)
							f[s][k + 1][i + 1][j - 2] = (f[s][k + 1][i + 1][j - 2] + 1LL * f[s][k][i][j] * p % mod) % mod;
						f[s][k + 1][i][j] = (f[s][k + 1][i][j] + 1LL * f[s][k][i][j] * ((1 - p + mod) % mod) % mod) % mod;
					}
		for (int i = 0; i < n; i ++ )
			sum[s] = (sum[s] + 1LL * (i + 1) * f[s][i][6][1] % mod * 3 % mod * qpow(n - i, mod - 2) % mod) % mod;
	}
	while (t -- )
	{
		int cnt[20] = {0};
		int id_cnt = 0;
		map<string, int> id;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i += 2)
		{
			string t;
			t += s[i];
			t += s[i + 1];
			if (id[t] == 0)
				id[t] = ++ id_cnt, cnt[id[t]] ++;
			else cnt[id[t]] ++;
		}

		int m = 0;
		for (int i = 1; i <= id_cnt; i ++ )
			if (cnt[i] == 2) m ++; 
		printf("Case #%d: %d\n", ++kase, sum[m]);

	}
	return 0;
}