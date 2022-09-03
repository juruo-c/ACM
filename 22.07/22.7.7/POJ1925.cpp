#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 5005, M = 1000005, INF = 0x3f3f3f3f;

int n;
int x[N], y[N];
LL l[N];
int f[M];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
			scanf("%d%d", &x[i], &y[i]);

		for (int i = 2; i <= n; i ++ )
			l[i] = 1LL * y[i] * y[i] - 1LL * (y[i] - y[1]) * (y[i] - y[1]);

		memset(f, 0x3f, sizeof f);
		f[x[1]] = 0;
		for (int i = 2; i <= n; i ++ )
			for (int j = x[i] - 1; j >= x[1]; j -- )
			{
				if (1LL * (x[i] - j) * (x[i] - j) > l[i]) break;
				if (f[j] == INF) continue;
				int t = min(2 * x[i] - j, x[n]);
				f[t] = min(f[t], f[j] + 1);
			}

		if (f[x[n]] == INF) puts("-1");
		else printf("%d\n", f[x[n]]);
	}
	return 0;
}