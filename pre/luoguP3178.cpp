#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
int w[N], wt[N];
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

int son[N], siz[N], dep[N], fa[N];
int top[N], id[N], dfs_cnt;

void dfs1(int u, int ff)
{
	dep[u] = dep[ff] + 1;
	fa[u] = ff;
	siz[u] = 1;
	int mxson = -1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[v] > mxson) mxson = siz[v], son[u] = v;
	}
}

void dfs2(int u, int topv)
{
	id[u] = ++ dfs_cnt;
	wt[dfs_cnt] = w[u];
	top[u] = topv;
	if (!son[u])
		return;
	dfs2(son[u], topv);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

struct T
{
	int l, r;
	LL sum, lz;
}t[N << 2];

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void push_down(int i )
{
	if (t[i].lz)
	{
		t[i << 1].lz += t[i].lz;
		t[i << 1 | 1].lz += t[i].lz;
		t[i << 1].sum += t[i].lz * (t[i << 1].r - t[i << 1].l + 1);
		t[i << 1 | 1].sum += t[i].lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1);
		t[i].lz = 0;
	}
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].sum = wt[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void updateOne(int i, int pos, int k)
{
	if (t[i].l == t[i].r)
	{
		t[i].sum += k;
		t[i].lz += k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (pos <= mid) updateOne(i << 1, pos, k);
	else updateOne(i << 1 | 1, pos, k);
	push_up(i);
}

void updateRange(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].sum += 1LL * k * (t[i].r - t[i].l + 1);
		t[i].lz += k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) updateRange(i << 1, l, r, k);
	if (r > mid) updateRange(i << 1 | 1, l, r, k);
	push_up(i);
}

LL query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	LL s = 0;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

LL queryR(int x, int y)
{
	LL ans = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += query(1, id[top[x]], id[x]);
		x = fa[top[x]];
	}
	if (id[x] > id[y]) swap(x, y);
	ans += query(1, id[x], id[y]);
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}

	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);

	for (int i = 1; i <= m; i ++ )
	{
		int op;
		int x, a;
		scanf("%d%d", &op, &x);
		if (op == 3)
			printf("%lld\n", queryR(x, 1));
		else
		{
			scanf("%d", &a);
			if (op == 1) updateOne(1, id[x], a);
			else updateRange(1, id[x], id[x] + siz[x] - 1, a);
		}
	}

	return 0;
}