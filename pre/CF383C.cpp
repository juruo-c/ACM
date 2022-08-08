#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 200005;

int n, m;
int a[N];
int L[N], R[N];
int dfscnt, dep[N];
int c[N];

struct edge
{
	int to, next;
}e[N << 1];
int head[N], cnt;

void add(int u, int v)
{
	e[++ cnt] = edge{v, head[u]};
	head[u] = cnt;
}

void update(int x, int k)
{	
	for (int i = x; i <= n; i += (i & -i))
		c[i] += k;
}

int query(int x)
{
	int res = 0;
	for (int i = x; i; i -= (i & -i))
		res += c[i];
	return res;
}

void dfs(int u, int ff)
{
	L[u] = ++ dfscnt;
	dep[u] = dep[ff] + 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u);
	}
	R[u] = dfscnt;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}

	dfs(1, 0);

	for (int i = 1; i <= m; i ++ )
	{
		int op, x, val;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			scanf("%d", &val);
			if (dep[x] & 1) update(L[x], val), update(R[x] + 1, -val);
			else update(L[x], -val), update(R[x] + 1, val);
		}
		else
		{
			int ans = query(L[x]);
			if (dep[x] & 1) ans += a[x];
			else ans = a[x] - ans;
			printf("%d\n", ans);
		}
	}

	return 0;
}