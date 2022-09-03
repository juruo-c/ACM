#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000005;

int n;
struct edge
{
	int to, next, w;
}e[N << 1];
int head[N], cnt;
int siz[N];
LL ans;

void add(int u, int v, int w)
{
	e[++ cnt] = edge{v, head[u], w};
	head[u] = cnt;
}

void dfs(int u, int ff)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u);
		siz[u] += siz[v];
		ans += 1LL * e[i].w * abs(2 * siz[v] - n);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i ++ )
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}