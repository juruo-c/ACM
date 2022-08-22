#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 10005;

int n;
struct edge
{
	int to, next;
}e[N << 1];
int head[N], cnt;
int f[N][16];

void add(int u, int v)
{
	e[++ cnt] = edge{v, head[u]};
	head[u] = cnt;
}

void dfs(int u, int ff)
{
	for (int i = 1; i <= 15; i ++ ) f[u][i] = i;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u);
		for (int j = 1; j <= 15; j ++ )
		{
			int mi = 0x3f3f3f3f;
			for (int k = 1; k <= 15; k ++ )
				if (k != j)
					mi = min(mi, f[v][k]);
			f[u][j] += mi;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}

	dfs(1, 0);

	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= 15; i ++ )
		ans = min(ans, f[1][i]);

	printf("%d\n", ans);

	return 0;
}