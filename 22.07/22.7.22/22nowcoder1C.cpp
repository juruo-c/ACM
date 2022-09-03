#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n, m, k, q;
int x[N], y[N];
int minx[N];
int ans[N];

long long solve()
{
	for (int i = 1; i <= m; i ++)
		minx[i] = n + 1, ans[i] = n + 1;
	for (int i = 1; i <= k; i ++ )
		ans[y[i]] = minx[y[i]] = min(minx[y[i]], x[i]);

	// for (int i = 1; i <= m; i ++ )
	// 	cout << "i = " << i << " ans[i] = " << ans[i] << endl;

	int lastx = minx[1], lasty = 1;
	for (int i = 2; i <= m; i ++ )
	{
		int x = minx[i], y = i;
		if (1LL * (y - 1) * lastx > 1LL * x * (lasty - 1))
			lastx = x, lasty = y;
		else
			ans[i] = (1LL * (y - 1) * lastx + lasty - 2) / (lasty - 1);
	}

	// for (int i = 1; i <= m; i ++ )
	// 	cout << "i = " << i << " ans[i] = " << ans[i] << endl;

	lastx = minx[m], lasty = m;
	for (int i = m - 1; i >= 1; i -- )
	{
		int x = minx[i], y = i;
		if (1LL * (y - m) * lastx < 1LL * x * (lasty - m))
			lastx = x, lasty = y;
		else
		{
			// cout << "i = " << i << endl;
			// cout << "lastx = " << lastx << " lasty = " << lasty << " x = " << x << " y = " << y ;
			// cout << " " << (1LL * (y - m) * lastx + lasty - m - 1) / (lasty - m) << endl;
			ans[i] = min(1LL * ans[i], (1LL * (m - y) * lastx + m - lasty - 1) / (m - lasty));
		}
	}

	// for (int i = 1; i <= m; i ++ )
	// 	cout << "i = " << i << " ans[i] = " << ans[i] << endl;

	long long res = 0;
	for (int i = 1; i <= m; i ++ )
		res += ans[i] - 1;
	return res;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; i ++ )
		scanf("%d%d", &x[i], &y[i]);

	for (int i = 1; i <= q; i ++ )
	{
		int pi, xi, yi;
		scanf("%d%d%d", &pi, &xi, &yi);
		x[pi] = xi, y[pi] = yi;
		printf("%lld\n", solve());
	}

	return 0;
}