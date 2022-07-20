#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 500005, mod = 1000000007;

int n;
int a[N];
int cnt[N], miu[N];
bool vis[N];
int p[N];
int pow2[N];

void getmiu(int n)
{
	miu[1] = 1;
	for (int i = 2; i <= n; i ++ )
	{
		if (!vis[i])
		{
			p[++ p[0]] = i;
			miu[i] = -1;
		}
		for (int j = 1; j <= p[0] && i * p[j] <= n; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0)
			{
				miu[i * p[j]] = 0;
				break;
			}
			miu[i * p[j]] = -miu[i];
		}
	}
}

int main()
{
	scanf("%d", &n);
	
	pow2[0] = 1;
	for (int i = 1; i <= n; i ++ )
		pow2[i] = pow2[i - 1] * 2 % mod;

	int mx = 0;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
		cnt[a[i]] ++;
	}

	getmiu(mx);

	LL ans = pow2[n] - 1;
	for (int i = 2; i <= mx; i ++ )
	{
		int sum = 0;
		for (int j = i; j <= mx; j += i)
			sum = (sum + cnt[j]) % mod;
		ans = (ans + 1LL * miu[i] * (pow2[sum] - 1) % mod + mod) % mod;
	}

	printf("%lld\n", ans);

	return 0;
}