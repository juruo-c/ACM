#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 2005;

int n, m, v, e;
int w[N][N];
int c[N], d[N];
double k[N];
double f[N][N][2];

void floyd()
{
	for (int k = 1; k <= v; k ++ )
		for (int i = 1; i <= v; i ++ )
			for (int j = 1; j <= v; j ++ )
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &v, &e);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &d[i]);
	for (int i = 1; i <= n; i ++ ) 
		scanf("%lf", &k[i]);
	for (int i = 1; i <= v; i ++ )
		for (int j = 1; j < i; j ++ )
			w[i][j] = w[j][i] = 1e9;
	for (int i = 1; i <= e; i ++ ) 
	{
		int u, v, wi;scanf("%d%d%d", &u, &v, &wi);
		w[u][v] = w[v][u] = min(w[u][v], wi);
	}

	floyd();

	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j <= m; j ++ )
			f[i][j][0] = f[i][j][1] = 1e18;

	f[1][0][0] = 0, f[1][1][1] = 0;
	for (int i = 2; i <= n; i ++ )
		for (int j = 0; j <= m; j ++ )
		{
			f[i][j][0] = min(f[i - 1][j][0] + w[c[i - 1]][c[i]], f[i - 1][j][1] + k[i - 1] * w[d[i - 1]][c[i]] + (1 - k[i - 1]) * w[c[i - 1]][c[i]]);
			if (j)
				f[i][j][1] = min(f[i - 1][j - 1][0] + k[i] * w[c[i - 1]][d[i]] + (1 - k[i]) * w[c[i - 1]][c[i]], 
					f[i - 1][j - 1][1] + k[i - 1] * k[i] * w[d[i - 1]][d[i]] + k[i - 1] * (1 - k[i]) * w[d[i - 1]][c[i]] + 
					(1 - k[i - 1]) * k[i] * w[c[i - 1]][d[i]] + (1 - k[i - 1]) * (1 - k[i]) * w[c[i - 1]][c[i]]);
			// f[i][j][0] = min(f[i - 1][j][0] + w[c[i - 1]][c[i]],f[i - 1][j][1] + w[d[i - 1]][c[i]] * p[i - 1] + (1 - p[i - 1]) * w[c[i - 1]][c[i]]);
   //          if(j)
   //              f[i][j][1] = min(f[i - 1][j - 1][0] + p[i] * w[c[i - 1]][d[i]] + (1 - p[i]) * w[c[i - 1]][c[i]],f[i - 1][j - 1][1]+ w[c[i - 1]][c[i]] * (1 - p[i]) * (1 - p[i - 1]) + w[d[i - 1]][d[i]] * p[i] * p[i - 1] +w[c[i - 1]][d[i]] * (1 - p[i - 1]) * p[i] + w[d[i - 1]][c[i]] * p[i - 1] * (1 - p[i]));

		}

	double ans = 1e18;
	for (int i = 0; i <= m; i ++ )
		ans = min(ans, min(f[n][i][0], f[n][i][1]));

	printf("%.2f\n", ans);

	return 0;
}