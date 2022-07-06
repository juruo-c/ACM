#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 305;

int n, m;
struct edge
{
	int to, next;
}e[N << 1];
int head[N], cnt;
int siz[N], f[N][N], s[N];

void add(int u, int v)
{
	e[++ cnt] = edge{v, head[u]};
	head[u] = cnt;
}

void dfs(int u, int ff)
{
	f[u][1] = s[u];
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u);
		siz[u] += siz[v];
		for (int j = min(m, siz[u]); j; j --)
			for (int k = 1; k <= min(j, siz[v]) && k < j; k ++ )
				f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	m ++;
	for (int i = 1; i <= n; i ++ )
	{
		int k;
		scanf("%d%d", &k, &s[i]);
		add(k, i);add(i, k);
	}

	dfs(0, -1);

	printf("%d\n", f[0][m]);

	return 0;
}