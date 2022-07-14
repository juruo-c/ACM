#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 205, INF = 1e9;

int n, T;
int l[N], r[N];
int t[N << 1];
int cnt;
int f[N << 1][N];
int g[N << 1][N];
int h[N << 1][N << 1];
int c[N << 1][N << 1];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) 
	{
		scanf("%d%d", &l[i], &r[i]);
		r[i] += l[i] - 1;
		t[++ cnt] = l[i];
		t[++ cnt] = r[i];
	}
	sort(t + 1, t + 1 + cnt);
	T = unique(t + 1, t + 1 + cnt) - t - 1;
	for (int i = 1; i <= n; i ++ )
	{
		l[i] = lower_bound(t + 1, t + 1 + T, l[i]) - t;
		r[i] = lower_bound(t + 1, t + 1 + T, r[i]) - t;
	}
	T += 2;

	for (int i = 1; i <= T; i ++ )
		for (int j = i; j <= T; j ++ )
			for (int k = 1; k <= n; k ++ )
				if (l[k] >= i && r[k] <= j) c[i][j] ++;

	for (int i = 0; i <= T + 1; i ++ )
		for (int j = 0; j <= n; j ++ )
			f[i][j] = g[i][j] = -INF;
	f[0][0] = g[T + 1][0] = 0;

	for (int i = 1; i <= T; i ++ )
		for (int j = 0; j <= c[1][i]; j ++ )
			for (int k = 0; k < i; k ++ )
			{
				f[i][j] = max(f[i][j], f[k][j] + c[k + 1][i]);
				if (j >= c[k + 1][i])
					f[i][j] = max(f[i][j], f[k][j - c[k + 1][i]]);
			}

	int ans = 0;
	for (int i = 0; i <= n; i ++ )
		ans = max(ans, min(f[T][i], i));
	printf("%d\n", ans);

	for (int i = T; i >= 1; i --)
		for (int j = 0; j <= c[i][T]; j ++ )
			for (int k = i + 1; k <= T + 1; k ++ )
			{
				g[i][j] = max(g[k][j] + c[i][k - 1], g[i][j]);
				if (j >= c[i][k - 1]) g[i][j] = max(g[i][j], g[i][j - c[i][k - 1]]);
			}

	for (int i = 1; i <= T; i ++ )
		for (int j = i + 2; j <= T; j ++ )
		{
			h[i][j] = -INF;
			for (int x = 0, y = n; x <= n; x ++ )
			{
				if (f[i][x] < 0) break;
				while (y >= 0)
				{
					int tmp = min(f[i][x] + g[j][y], x + y + c[i + 1][j - 1]);
					if (tmp >= h[i][j]) h[i][j] = tmp;
					else break;
					y --;
				}
				y ++;
			}
		}

	for (int i = 1; i <= n; i ++ )
	{
		ans = 0;
		for (int L = 1; L < l[i]; L ++ )
			for (int R = r[i] + 1; R <= T; R ++ )
				ans = max(ans, h[L][R]);
		printf("%d\n", ans);
	}

	return 0;
}