#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long LL;

const int N = 505;

int n, m;
char a[N][N];
int b[N][N];

int calc(int i, int j)
{
	int res = 3;
	int l = j - 1, r = j + 1, u = i - 1, d = i + 1;
	if (l >= 1 && u >= 1) res = min(res, b[i][l] + b[i][j] + b[u][j]);
	if (l >= 1 && d <= n) res = min(res, b[i][j] + b[i][l] + b[d][j]);
	if (r <= m && u >= 1) res = min(res, b[i][j] + b[i][r] + b[u][j]);
	if (r <= m && d <= n) res = min(res, b[i][j] + b[i][r] + b[d][j]);
	return res;
}

int main()
{
	#ifdef ZYCMH
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif 

	int t;
	scanf("%d", &t);
	while(t --)
	{
		scanf("%d%d", &n, &m);
		int c1 = 0;
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%s", a[i] + 1);
			for (int j = 1; j <= m; j ++ )
				b[i][j] = a[i][j] - '0', c1 += b[i][j];
		}

		int mi = 3;
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				mi = min(mi, calc(i, j));

		if (mi == 2) c1 --;
		else if (mi == 3) c1 -= 2;

		printf("%d\n", c1);
	}

	return 0;
}