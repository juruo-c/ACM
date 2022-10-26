#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, k;
int val[N];
struct edge
{
	int to, next;
}e[N];
int head[N], cnt;
int siz[N], dep[N], son[N];

struct Tree
{
	int l, r;
	int sum;
}t[N * 50];
int t_cnt;
int rt[N];

LL ans;

void add(int u, int v)
{
	e[++ cnt] = {v, head[u]};
	head[u] = cnt;
}

void push_up(int i)
{
	t[i].sum = t[t[i].l].sum + t[t[i].r].sum;
}

void update(int& i, int l, int r, int pos, int k)
{
	if (!i) i = ++ t_cnt;
	if (l == r)
	{
		t[i].sum += k;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(t[i].l, l, mid, pos, k);
	else update(t[i].r, mid + 1, r, pos, k);
	push_up(i);
}

int query(int i, int l, int r, int ql, int qr)
{
	if (!i) return 0;
	if (ql <= l && r <= qr)
		return t[i].sum;
	int mid = (l + r) >> 1;
	int s = 0;
	if (ql <= mid) s += query(t[i].l, l, mid, ql, qr);
	if (qr > mid) s += query(t[i].r, mid + 1, r, ql, qr);
	return s; 
}

void dfs(int u, int ff)
{
	dep[u] = dep[ff] + 1;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		dfs(v, u);
		siz[u] += siz[v];
		if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
	}
}

void updateAns(int u, int lca)
{
	int Dep = 2 * dep[lca] + k - dep[u];
	int Val = 2 * val[lca] - val[u];
	if (Val >= 0 && Val <= n && Dep >= dep[lca] + 1)
		ans += query(rt[Val], 1, n, dep[lca] + 1, min(Dep, n));
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		updateAns(v, lca);
	}
}

void modify(int u, int k)
{
	update(rt[val[u]], 1, n, dep[u], k);
	for (int i = head[u]; i; i = e[i].next)
		modify(e[i].to, k);
}

void dsu(int u, int k)
{
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == son[u]) continue;
		dsu(v, 0);
	}
	if (son[u]) dsu(son[u], 1);

	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == son[u]) continue;
		updateAns(v, u);
		modify(v, 1);
	}

	update(rt[val[u]], 1, n, dep[u], 1);

	if (!k) modify(u, -1);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &val[i]);
	for (int i = 2; i <= n; i ++ ) 
	{
		int p;scanf("%d", &p);
		add(p, i);
	}

	dfs(1, 0);
	dsu(1, 0);

	printf("%lld\n", ans * 2);

	return 0;
}