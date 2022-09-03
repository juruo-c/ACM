#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 4005;
const LL INF = 1e18;

int t[N], c[N];
LL f[N];

int main()
{
	int n;
	scanf("%d", &n);
	int mxt = 0;
	for (int i = 1; i <= n; i ++ ) scanf("%d%d", &t[i], &c[i]), t[i] ++, mxt = max(mxt, t[i]);

	int m = 4000;
	for (int i = 1; i <= m; i ++ ) f[i] = INF;
	for (int i = 1; i <= n; i ++ )
		for (int j = m; j >= t[i]; j -- )
			f[j] = min(f[j], f[j - t[i]] + c[i]);

	LL ans = INF;
	for (int i = n; i <= m; i ++ )
		ans = min(ans, f[i]);
	printf("%lld\n", ans);

	return 0;
}