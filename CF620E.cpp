#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 400005;

int n, m;
int c[N], ci[N];
struct T
{
	int l, r;
	LL col;
	int lz;
}t[N << 2];

struct edge
{
	int to, next;
}e[N << 1];
int head[N], cnt;

int dfscnt, l[N], r[N];

void add(int u, int v)
{
	e[++ cnt] = edge{v, head[u]};
	head[u] = cnt;
}

void dfs(int u, int ff)
{
	l[u] = ++ dfscnt;
	ci[dfscnt] = c[u];
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u);
	}
	r[u] = dfscnt;
}

void push_up(int i)
{
	t[i].col = t[i << 1].col | t[i << 1 | 1].col;
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].col = 1LL << ci[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void push_down(int i)
{
	if (t[i].lz)
	{
		t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
		t[i << 1].col = 1LL << t[i].lz;
		t[i << 1 | 1].col = 1LL << t[i].lz;
		t[i].lz = 0;
	}
}

void update(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].lz = k;
		t[i].col = 1LL << k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r, k);
	if (r > mid) update(i << 1 | 1, l, r, k);
	push_up(i);
}

LL query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
		return t[i].col;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	LL res = 0;
	if (l <= mid) res |= query(i << 1, l, r);
	if (r > mid) res |= query(i << 1 | 1, l, r);
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}

	dfs(1, 0);

	build(1, 1, n);
	for (int i = 1; i <= m; i ++ )
	{
		int op, u, c;
		scanf("%d%d", &op, &u);
		if (op == 1)
		{
			scanf("%d", &c);
			update(1, l[u], r[u], c);
		}
		else
		{
			LL t = query(1, l[u], r[u]);
			int ans = 0;
			for (LL i = t; i; i -= (i & -i))
				ans ++;
			printf("%d\n", ans);
		}
	}
	return 0;
}