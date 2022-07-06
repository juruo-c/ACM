#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 500005;

int n, k;
struct edge
{
	int to, next, w;
}e[N << 1];
int head[N], cnt;
int siz[N];
LL f[N], g[N];
LL down1[N], down2[N], up[N];

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
		if (v == ff) continue;
		dfs(v, u);
		siz[u] += siz[v];
		if (siz[v])
		{
			f[u] += f[v] + 2 * e[i].w;
			int t = down1[v] + e[i].w;
			if (down1[u] < t) 
			{
				down2[u] = down1[u];
				down1[u] = t;
			}
			else if(down2[u] < t) down2[u] = t;
		}
	}
}

void dfs_(int u, int ff)
{
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;

		if (k - siz[v])
		{
			g[v] = g[u] + f[u] - f[v];
			if (!siz[v]) g[v] += 2 * e[i].w;

			if (down1[u] == e[i].w + down1[v]) up[v] = max(up[u], down2[u]) + e[i].w;
			else up[v] = max(up[u], down1[u]) + e[i].w;
		}

		dfs_(v, u);
	}
}

int main()
{	
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i ++ )
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i ++ )
	{
		int x;scanf("%d", &x);
		siz[x] = 1;
	}

	dfs(1, 0);
	dfs_(1, 0);

	for (int i = 1; i <= n; i ++ )
		printf("%lld\n", g[i] + f[i] - max(up[i], down1[i]));

	return 0;	
}