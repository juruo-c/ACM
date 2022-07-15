#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 205, INF = 1e9;

int n;
int l[N], r[N];
int t[N << 1], T;
int f[N << 1][N], g[N << 1][N];
int c[N << 1][N << 1], s[N << 1][N << 1];

int calc(int x, int y, int L, int R)
{
	return min(f[L][x] + g[R][y], x + y + c[L][R]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d%d", &l[i], &r[i]);
		r[i] += l[i];
		t[++ T] = l[i];
		t[++ T] = r[i];
	}
	
	sort(t + 1, t + 1 + T);
	T = unique(t + 1, t + 1 + T) - t - 1;
	for (int i = 1; i <= n; i ++ )
	{
		l[i] = lower_bound(t + 1, t + T + 1, l[i]) - t;
		r[i] = lower_bound(t + 1, t + T + 1, r[i]) - t;
	}
	
	for (int i = 1; i <= T; i ++ )
		for (int j = i + 1; j <= T; j ++ )
			for (int k = 1; k <= n; k ++ )
				if (l[k] >= i && r[k] <= j) c[i][j] ++;

	for (int i = 1; i <= T; i ++ )
		for (int j = 1; j <= n; j ++ ) 
			f[i][j] = g[i][j] = -INF;

	for (int i = 1; i <= T; i ++ )
		for (int j = 0; j <= c[1][i]; j ++ )
			for (int k = 0; k < i; k ++ )
			{
				f[i][j] = max(f[i][j], f[k][j] + c[k][i]);
				f[i][j] = max(f[i][j], f[k][max(0, j - c[k][i])]);
			}

	for (int i = T - 1; i >= 1; i -- )
		for (int j = 0; j <= c[i][T]; j ++ )
			for (int k = i + 1; k <= T; k ++ )
			{
				g[i][j] = max(g[i][j], g[k][j] + c[i][k]);
				g[i][j] = max(g[i][j], g[k][max(0, j - c[i][k])]);
			}

	for (int L = 1; L <= T; L ++ )
		for (int R = L + 1; R <= T; R ++ )
			for (int x = 0, y = n; x <= n; x ++ )
			{
				while (y && calc(x, y, L, R) <= calc(x, y - 1, L, R)) y --;
				s[L][R] = max(s[L][R], calc(x, y, L, R));
			}

	int ans = 0;
	for (int i = 0; i <= T; i ++ )
		ans = max(ans, min(f[T][i], i));
	printf("%d\n", ans);

	for (int i = 1; i <= n; i ++ )
	{
		ans = 0;
		for (int L = 1; L <= l[i]; L ++ )
			for (int R = r[i]; R <= T; R ++ )
				ans = max(ans, s[L][R]);
		printf("%d\n", ans);
	}

	return 0;
}