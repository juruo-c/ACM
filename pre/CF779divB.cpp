#include <iostream>

using namespace std;

typedef long long LL;
const int mod = 998244353;

int main()
{
	int t;cin >> t;
	while (t --)
	{
		int n;
		cin >> n;
		if (n % 2)
		{
			cout << 0 << endl;
			continue;
		}
		LL ans = 1;
		for (int i = 1; i <= n / 2; i ++ )
			ans = ans * i % mod;
		ans = ans * ans % mod;
		cout << ans << endl;
	}
	return 0;
}