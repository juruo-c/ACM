#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000005;

bool vis[N];
int p[N];

void getprime(int n)
{
	for (int i = 2; i <= n; i ++ )
	{
		if (!vis[i]) p[++ p[0]] = i;
		for (int j = 1; j <= p[0] && i * p[j] <= n; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	getprime(n);
	for (int i = 1; i <= p[0]; i ++ )
	{
		int t = p[i];
		int ans = 0;
		for (int j = n; j; j /= t) ans += j / t;
		cout << t << " " << ans << endl;
	}
	return 0;
}