#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

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
};

int son[N], siz[N], fa[N], dep[N];

void dfs1(int u, int ff)
{
	dep[u] = dep[ff] + 1;
	siz[u] = 1;
	fa[u] = ff;
	int mxson = -1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (mxson < siz[v]) son[u] = v, mxson = siz[v];
	}
}

int dfs_cnt, id[N], top[N];

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
	int sum, lz;
}t[N << 2];

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r, t[i].lz = -1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void push_down(int i)
{
	if (t[i].lz != -1)
	{
		t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
		t[i << 1].sum = t[i].lz * (t[i << 1].r -  t[i << 1].l + 1);
		t[i << 1 | 1].sum = t[i].lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1);
		t[i].lz = -1;
	}
}

void update(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r) 
	{
		t[i].lz = k;
		t[i].sum = k * (t[i].r - t[i].l + 1);
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r, k);
	if (r > mid) update(i << 1 | 1, l, r, k);
	push_up(i);
}

int query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	int s = 0;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

int updateR(int x, int y, int k)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		update(1, id[top[x]], id[x], k);
		x = fa[top[x]];
	}
	if (id[x] > id[y]) swap(x, y);
	update(1, id[x], id[y], k);
}

int queryR(int x, int y)
{
	int res = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		res += query(1, id[top[x]], id[x]);
		x = fa[top[x]];
	}
	if (id[x] > id[y]) swap(x, y);
	res += query(1, id[x], id[y]);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i ++ )
	{
		int p;
		scanf("%d", &p);
		p ++;
		add(p, i);
		add(i, p);
	}

	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);

	scanf("%d", &q);
	for (int i = 1; i <= q; i ++ )
	{
		char op[10];
		int x;
		scanf("%s%d", op, &x);
		x ++;
		if (op[0] == 'i')
		{
			if (queryR(x, x)){
				puts("0");
				continue;
			}
			// printf("%d %d %d\n", x, dep[x], queryR(x, 1));
			printf("%d\n", dep[x] - queryR(x, 1));
			updateR(x, 1, 1);
		}
		else
		{
			if (!queryR(x, x))
			{
				puts("0");
				continue;
			}
			printf("%d\n", query(1, id[x], id[x] + siz[x] - 1));
			update(1, id[x], id[x] + siz[x] - 1, 0);
		}
	}

	return 0;
}