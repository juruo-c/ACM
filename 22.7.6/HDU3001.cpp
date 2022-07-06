#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 15, M = 60005, INF = 0x3f3f3f3f;

int n, m;
int edge[N][N];
int f[N][M];
int pow3[N];
int bit[M][N];

int main()
{
	pow3[0] = 1;
	for (int i = 1; i < 11; i ++ ) pow3[i] = pow3[i - 1] * 3;

	for (int i = 0; i < pow3[10]; i ++ )
	{
		int t = i;
		for (int j = 0; j < 10; j ++ )
		{
			bit[i][j] = t % 3;
			t /= 3;
		}
	}

	while (~scanf("%d%d", &n, &m))
	{
		memset(edge, 0, sizeof edge);
		memset(f, 0x3f, sizeof f);
		for (int i = 1; i <= m; i ++ )
		{
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			u --, v --;
			if (!edge[u][v]) edge[u][v] = edge[v][u] = c;
			else edge[u][v] = edge[v][u] = min(edge[u][v], c);
		}

		for (int i = 0; i < n; i ++ )
			f[i][pow3[i]] = 0;

		for (int i = 0; i < pow3[n]; i ++ )
		{
			for (int j = 0; j < n; j ++ )
			{
				if (f[j][i] == INF || bit[i][j] == 0) continue;
				for (int k = 0; k < n; k ++ )
				{
					if (k == j || bit[i][k] == 2 || !edge[j][k]) continue;
					int t = i + pow3[k];
					f[k][t] = min(f[k][t], f[j][i] + edge[j][k]);
				}
			}
		}

		int ans = INF;
		for (int i = 0; i < pow3[n]; i ++ )
		{
			bool flag = true;
			for (int j = 0; j < n; j ++ )
				if (!bit[i][j])
				{
					flag = false;
					break;
				}
			if (flag) 
			{
				for (int j = 0; j < n; j ++ )
					ans = min(ans, f[j][i]);
			}
		}

		if (ans == INF)
			puts("-1");
		else printf("%d\n", ans);

	}

	return 0;
}