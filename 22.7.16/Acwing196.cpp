#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000005;

int l, r;
int p[N];
bool vis[N];
bool st[N];

void getprime(int n) //获得n范围内的所有素数
{
	p[0] = 0;
	memset(vis, false ,sizeof vis);
	for (int i = 2; i <= n; i ++ )
	{
		if (!vis[i]) p[++ p[0]] = i;
		for (int j = 1; j <= p[0] && p[j] * i <= n; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int main()
{
	int l, r;
	while (cin >> l >> r)
	{
		getprime(50000);
		memset(st, false, sizeof st);
		for (int i = 1; i <= p[0]; i ++ )
		{
			long long t = p[i];
			for (long long j = max(t * 2, (l + t - 1) / t * t); j <= r; j += t)
				st[j - l] = true;
		}
		int cnt = 0;
		for (int i = 0; i <= r - l; i ++ )
			if (!st[i] && i + l >= 2)
				p[ ++ cnt] = i + l;

		if (cnt < 2) cout << "There are no adjacent primes." << endl;
		else
		{
			int mx1, mx2, mx = 0;
			int mi1, mi2, mi = N;
			for (int i = 1; i < cnt; i ++ )
			{
				if (mx < p[i + 1] - p[i])
				{
					mx = p[i + 1] - p[i];
					mx1 = p[i], mx2 = p[i + 1];
				}
				if (mi > p[i + 1] - p[i])
				{
					mi = p[i + 1] - p[i];
					mi1 = p[i], mi2 = p[i + 1];
				}
			}
			cout << mi1 << "," << mi2 << 
			" are closest, " << mx1 << "," << mx2 << " are most distant." << endl;
		}

	}
	return 0;
}