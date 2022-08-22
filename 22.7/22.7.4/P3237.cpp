#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long double LD;

const int N = 500005;

int n;
int a[N];
struct edge
{
	int to, next;
}e[N << 1];
int head[N], cnt;
int siz[N];
LD f[N];

void add(int u, int v)
{
	e[++ cnt] = edge{v, head[u]};
	head[u] = cnt;
}

void dfs(int u, int ff, LD sum)
{
	f[u] = sum + log(a[u]);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u, sum + log(siz[u]));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
		siz[u] ++;
	}

	dfs(1, 0, 0);

	sort(f + 1, f + 1 + n);

	int res = 1, ans = 0;
	for (int i = 2; i <= n; i ++ )
		if (f[i] - f[i - 1] <= 1e-9)
		{
			res ++;
			ans = max(ans, res);
		}
		else res = 1;

	printf("%d\n", n - ans);

	return 0;
}