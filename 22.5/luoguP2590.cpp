#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 30005;

int n, q;
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

int son[N], dep[N], fa[N], id[N], siz[N], top[N], dfs_cnt;

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
		if (mxson < siz[v]) son[u] = v, mxson = siz[v];
	}
}

void dfs2(int u, int topv)
{
	id[u] = ++ dfs_cnt;
	wt[dfs_cnt] = w[u];
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
	int mx, sum;
}t[N << 2];

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
	t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].mx = t[i].sum = wt[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update(int i, int pos, int k)
{
	if (t[i].l == t[i].r)
	{
		t[i].sum = t[i].mx = k;
		return;
	}
	int mid = (t[i].l + t[i].r) >> 1;
	if (pos <= mid) update(i << 1, pos, k);
	else update(i << 1 | 1, pos, k);
	push_up(i);
}

int queryS(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
		return t[i].sum;
	int mid = (t[i].l + t[i].r) >> 1;
	int s = 0;
	if (l <= mid) s += queryS(i << 1, l, r);
	if (r > mid) s += queryS(i << 1 | 1, l, r);
	return s;
}

int queryM(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].mx;
	int mid = (t[i].l + t[i].r ) >> 1;
	int mx = -0x3f3f3f3f;
	if (l <= mid) mx = max(mx, queryM(i << 1, l, r));
	if (r > mid) mx = max(mx, queryM(i << 1 | 1, l, r));
	return mx;
}

int queryRS(int x, int y)
{
	int ans = 0;
	while(top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += queryS(1, id[top[x]], id[x]);
		x = fa[top[x]];
	}
	if (id[x] > id[y]) swap(x, y);
	ans += queryS(1, id[x], id[y]);
	return ans;
}

int queryRM(int x, int y)
{
	int ans = -0x3f3f3f3f;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = max(ans, queryM(1, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (id[x] > id[y]) swap(x, y);
	ans = max(ans, queryM(1, id[x], id[y]));
	return ans;
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
	for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);

	scanf("%d", &q);
	for (int i = 1; i <= q; i ++ )
	{
		char op[10];
		scanf("%s", op);
		int u, v;
		scanf("%d%d", &u, &v);
		if (op[0] == 'Q')
		{
			if (op[1] == 'M') printf("%d\n", queryRM(u, v));
			else printf("%d\n", queryRS(u, v));
		}
		else 
			update(1, id[u], v);
	}

	return 0;
}