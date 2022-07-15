#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 205, M = 65;

int n, k;
int f[N][N * M];
int five[N], two[N];

int main()
{
	scanf("%d%d", &n, &k);
	int sum = 0;
	for (int i = 1; i <= n; i ++ )
	{
		LL x; scanf("%lld", &x);
		while (x % 5 == 0)
		{
			five[i] ++;
			x /= 5;
		}
		while (x % 2 == 0)
		{
			two[i] ++;
			x /= 2;
		}
		sum += two[i];
	}

	memset(f, -0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = k; j >= 1; j -- )
			for (int s = sum; s >= two[i]; s -- )
				f[j][s] = max(f[j][s], f[j - 1][s - two[i]] + five[i]);

	int ans = 0;
	for (int i = 1; i <= sum; i ++ )
		ans = max(ans, min(i, f[k][i]));

	printf("%d\n", ans);
	return 0;
}