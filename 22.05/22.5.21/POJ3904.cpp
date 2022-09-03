#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;
const int N = 10005;

int n;
int a[N];
int cnt[N];
int p[N];
bool vis[N];
int miu[N];

void getmiu()
{
	miu[1] = 1;
	for (int i = 2; i < N; i ++ )
	{
		if (!vis[i])
		{
			p[++ p[0]] = i;
			miu[i] = -1;
		}
		for (int j = 1; j <= p[0] && i * p[j] < N; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0) break;
			miu[i * p[j]] = -miu[i];
		}
	}
}

void getcnt()
{
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= sqrt(a[i]); j ++ )
		{
			if (a[i] % j == 0)
			{
				 cnt[j] ++;
				if (a[i] / j != j) cnt[a[i] / j] ++;
			}
		}
}

LL C4(int n)
{
	if (n < 4) return 0;
	return 1LL * n * (n - 1) * (n - 2) * (n - 3) / 24;
}

int main()
{
	getmiu();
	
	while(~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i ++ )
			scanf("%d", &a[i]);
		getcnt();
		LL ans = 0;
		for (int i = 1; i < N; i ++ )
			ans += 1LL * miu[i] * C4(cnt[i]);
		printf("%lld\n", ans);
	}

	return 0;
}