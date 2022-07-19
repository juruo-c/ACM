#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
	int t;
	cin >> t;
	int kase = 0;
	while (t -- )
	{
		int n;
		cin >> n;
		LL ans = 0;
		for (int l = 2, r; l <= n; l = r + 1)
		{
			r = n / (n / l);
			ans += 1LL * (l + r) * (r - l + 1) / 2 * (n / l - 1);
		}
		cout << "Case " << ++ kase << ": " << ans << endl;
	}
	return 0;
}