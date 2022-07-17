#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000005, mod = 10000007;

int n;
int p[N];
bool vis[N];

void getprime()
{
	for (int i = 2; i < N; i ++ )
	{
		if (!vis[i]) p[++ p[0]] = i;
		for (int j = 1; j <= p[0] && i * p[j] < N; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int main()
{
	getprime();
	while (scanf("%d", &n) && n)
	{
		int ans = 1;
		for (int i = 1; i <= p[0] && p[i] <= n; i ++ )
		{
			int t = p[i];
			int cnt = 0;
			for (int j = n; j; j /= t) cnt += j / t;
			ans = ans * (1LL * (cnt + 1) * (cnt + 2) / 2) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
