#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005;

int n, m, rt, p;
int w[N], wt[N];
//
struct E
{
	int to, next;
}e[N << 1];
int head[N], cnt;

void add(int u, int v)
{
	e[++ cnt] = E{v, head[u]};
	head[u] = cnt;
}

//
int hson[N], id[N], fa[N], dfs_cnt, dep[N], siz[N], top[N];

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
		if (siz[v] > mxson) hson[u] = v, mxson = siz[v];
	}
}

void dfs2(int u, int topv)
{
	id[u] = ++ dfs_cnt;
	wt[dfs_cnt] = w[u];
	top[u] = topv;
	if (!hson[u]) return;
	dfs2(hson[u], topv);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == fa[u] || v == hson[u]) continue;
		dfs2(v, v);
	}
}

// 
struct T
{
	int l, r;
	int sum, lz;
}t[N << 2];

void push_up(int i)
{
	t[i].sum = (t[i << 1].sum + t[i << 1 | 1].sum) % p;
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].sum = wt[l] % p;
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
		t[i << 1].lz = (t[i << 1].lz + t[i].lz) % p;
		t[i << 1 | 1].lz = (t[i << 1 | 1].lz + t[i].lz) % p;
		t[i << 1].sum = (t[i << 1].sum + 1LL * t[i].lz * (t[i << 1].r - t[i << 1].l + 1) % p) % p;
		t[i << 1 | 1].sum = (t[i << 1 | 1].sum + 1LL * t[i].lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1) % p ) % p;
		t[i].lz = 0;
	}
}

void update(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r) 
	{
		t[i].sum = (t[i].sum + 1LL * k * (t[i].r - t[i].l + 1) % p) % p;
		t[i].lz = (t[i].lz + k) % p;
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
	if (l <= t[i].l && t[i].r <= r)
		return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	int s = 0;
	if (l <= mid) s = (s + query(i << 1, l, r)) % p;
	if (r > mid) s = (s + query(i << 1 | 1, l, r)) % p;
	return s;
}

//
void updateR(int x, int y, int k)
{
	k %= p;
	while(top[x] != top[y])
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
	int ans = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = (ans + query(1, id[top[x]], id[x])) % p;
		x = fa[top[x]];
	}
	if (id[x] > id[y]) swap(x, y);
	return (ans + query(1, id[x], id[y])) % p;
}

void updateSon(int u, int k)
{
	update(1, id[u], id[u] + siz[u] - 1, k);
}

int querySon(int u)
{
	return query(1, id[u], id[u] + siz[u] - 1);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &rt, &p);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}

	dfs1(rt, 0);	
	dfs2(rt, rt);

	build(1, 1, n);

	for (int i = 1; i <= m; i ++ )
	{
		int op;
		int x, y, z;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			scanf("%d%d", &y, &z);
			updateR(x, y, z);
		}
		else if(op == 2)
		{
			scanf("%d", &y);
			printf("%d\n", queryR(x, y));
		}
		else if(op == 3)
		{
			scanf("%d", &z);
			updateSon(x, z);
		}
		else
			printf("%d\n", querySon(x));
	}
	return 0;
}