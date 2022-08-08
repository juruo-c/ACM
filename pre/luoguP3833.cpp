#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, q;
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

int son[N], siz[N], fa[N], dep[N];
int top[N], id[N], dfs_cnt;

void dfs1(int u, int ff)
{
	fa[u] = ff;
	dep[u] = dep[ff] + 1;
	siz[u] = 1;
	int mxson = -1;
	for (int i = head[u]; i; i =e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (mxson < siz[v]) mxson = siz[v], son[u] = v;
	}
}

void dfs2(int u, int topv)
{
	id[u] = ++ dfs_cnt;
	top[u] = topv;
	if (!son[u]) return;
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

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void push_down(int i)
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

void update(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].sum += 1LL * k * (t[i].r - t[i].l + 1);
		t[i].lz += k;
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
	if (l <= t[i].l && t[i].r <= r) return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	LL s = 0;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

void updateR(int x, int y, int d)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		update(1, id[top[x]], id[x], d);
		x = fa[top[x]];
	}
	if (id[x] > id[y]) swap(x, y);
	update(1, id[x], id[y], d);
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

	dfs1(0, -1);
	dfs2(0, 0);
	build(1, 1, n);

	scanf("%d", &q);
	for (int i = 1; i <= q; i ++ )
	{
		char op;
		int u, v, d;
		scanf("\n%c", &op);
		if (op == 'A')
		{
			scanf("%d%d%d", &u, &v, &d);
			updateR(u, v, d);
		}
		else
		{
			scanf("%d", &u);
			printf("%lld\n", query(1, id[u], id[u] + siz[u] - 1));
		}
	}

	return 0;
}