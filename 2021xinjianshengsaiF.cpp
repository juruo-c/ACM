#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 200005;

int n;
int c[N];
int siz[N];
struct edge
{
	int to, next, w;
}e[N << 1];
int head[N], cnt;
int sum;

LL f[N], g[N];

void add(int u, int v, int w)
{
	e[++ cnt] = edge{v, head[u], w};
	head[u] = cnt;
}

void dfs(int u, int ff)
{
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		int w = e[i].w;
		if (v == ff) continue;
		dfs(v, u);
		siz[u] += siz[v];
		f[u] += f[v] + 1LL * w * (siz[v] * w + 2 * g[v]);
		g[u] += g[v] + 1LL * siz[v] * w;
	}
}

void dfs_(int u, int ff)
{
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		int w = e[i].w;
		if (v == ff) continue;

		f[v] += (f[u] - f[v] - 1LL * w * (siz[v] * w + 2 * g[v])) +
		 1LL * w * ((sum - siz[v]) * w + 2 * (g[u] - g[v] - siz[v] * w));
		g[v] += (g[u] - g[v] - 1LL * siz[v] * w) + 1LL * w * (sum - siz[v]);
		dfs_(v, u);
	}
}

int main()
{	
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) 
		scanf("%d", &siz[i]), sum += siz[i];

	for (int i = 1; i < n; i ++ )
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}

	dfs(1, 0);

	dfs_(1, 0);

	LL ans = 1e18;
	for (int i = 1; i <= n; i ++ )
		ans = min(ans, f[i]);
	printf("%lld\n", ans);

	return 0;
}