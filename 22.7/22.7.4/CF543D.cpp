#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 200005, mod = 1000000007;

int n;
struct edge
{
	int to, next;
}e[N << 1];
int head[N], cnt;
int f[N], g[N];
vector<int> pre[N], suf[N];

void add(int u, int v)
{
	e[++ cnt] = {v, head[u]};
	head[u] = cnt;
}

void dfs(int u, int ff)
{
	f[u] = 1;
	pre[u].push_back(1), suf[u].push_back(1);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u);
		f[u] = 1LL * f[u] * (f[v] + 1) % mod;
		pre[u].push_back(f[v] + 1);
		suf[u].push_back(f[v] + 1);
	}
	pre[u].push_back(1), suf[u].push_back(1);
	for (int i = 1; i <= pre[u].size() - 2; i ++ )
		pre[u][i] = 1LL * pre[u][i - 1] * pre[u][i] % mod;
	for (int i = suf[u].size() - 2; i >= 1; i -- )
		suf[u][i] = 1LL * suf[u][i + 1] * suf[u][i] % mod;
}

void dfs_(int u, int ff)
{
	for (int i = head[u], j = 1; i; i = e[i].next, j ++ )
	{
		int v = e[i].to;
		if (v == ff) continue;

		g[v] = (1LL * g[u] * pre[u][j - 1] % mod * suf[u][j + 1] % mod + 1) % mod;

		dfs_(v, u);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i ++ )
	{
		int fa;
		scanf("%d", &fa);
		add(fa, i);
		add(i, fa);
	}
	dfs(1, 0);
	g[1] = 1;
	dfs_(1, 0);

	for (int i = 1; i <= n; i ++ )
		printf("%d ", 1LL * f[i] * g[i] % mod);

	return 0;
}