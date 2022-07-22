#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10000005;

int p[N];
int phi[N];
bool vis[N];

void getphi()
{
	for (int i = 2; i < N; i ++ )
	{
		if (!vis[i])
		{
			p[++ p[0]] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= p[0] && i * p[j] < N; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0)
			{
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
}

int qpow(int a, int b, int p)
{
	int ans = 1;
	while (b)
	{
		if (b & 1) ans = 1LL * ans * a % p;
		a = 1LL * a * a % p;
		b >>= 1;
	}
	return ans;
}

int solve(int a, int p)
{
	if (p == 1) return 0;
	return qpow(a, solve(a, phi[p]) + phi[p], p);
}

int main()
{
	getphi();
	int t, p;
	cin >> t;
	while (t --)
	{
		cin >> p;
		cout << solve(2, p) << endl;
	}
	return 0;
}