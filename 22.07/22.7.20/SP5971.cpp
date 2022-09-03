#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1000005;

int p[N], phi[N];
bool vis[N];
LL ans[N];

void pre()
{
	phi[1] = 1;
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

	for (int i = 1; i < N; i ++ )
		for (int j = 1; i * j < N; j ++ )
			ans[i * j] += (1LL * i * phi[i] + (i == 1))/ 2;

	for (int i = 1; i < N; i ++ )
		ans[i] *= i;
}

int main()
{
	pre();
	int t, n;
	cin >> t;
	while (t --)
	{
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}