#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10005, mod = 1000000007;

int n;
int p[N];
int c[N];
int f[N], g[N];
int ans[N];

void add(int x, int k)
{
	for (int i = x; i <= n; i += (i & -i))
		c[i] = (c[i] + k) % mod;
}

int query(int x)
{
	int res = 0;
	for (int i = x; i; i -= (i & -i))
		res = (res + c[i]) % mod;
	return res;
}

int main()
{
	int t;scanf("%d", &t);
	int kase = 0;
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) scanf("%d", &p[i]), f[i] = 1, ans[i] = 0;

		ans[1] = n;
		for (int i = 2; i <= n; i ++ )
		{
			memcpy(g, f, sizeof f);
			for (int j = 1; j <= n; j ++ ) c[j] = 0;
			for (int j = 1; j <= n; j ++ )
			{
				f[j] = query(p[j] - 1);
				add(p[j], g[j]);
				ans[i] = (ans[i] + f[j]) % mod;
			}
			if (ans[i] == 0) break;
		}

		printf("Case #%d:", ++ kase);
		for (int i = 1; i <= n; i ++ ) printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}