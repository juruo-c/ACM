#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 40005;

int p[N];
bool vis[N];
int phi[N];

void getphi(int n)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i ++ )
	{
		if (!vis[i]) 
		{
			phi[i] = i - 1;
			p[++ p[0]] = i;
		}
		for (int j = 1; j <= p[0] && i * p[j] <= n; j ++ )
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

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	getphi(n);
	int ans = 3;
	for (int i = 2; i < n; i ++ )
		ans += 2 * phi[i];
	cout << ans << endl;
	return 0;
}