#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n;
struct edge
{
	int to, next;
}e[N];
int head[N], cnt;
int siz[N], dfn[N], dfn_cnt;
int a[N], b[N];
struct T
{
	int l, r;
	int sum, lz;
}t[N << 2];
char str[5];

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void push_down(int i)
{
	if (t[i].lz)
	{
		t[i << 1].lz ^= 1;
		t[i << 1 | 1].lz ^= 1;
		t[i << 1].sum = t[i << 1].r - t[i << 1].l + 1 - t[i << 1].sum;
		t[i << 1 | 1].sum = t[i << 1 | 1].r - t[i << 1 | 1].l + 1 - t[i << 1 | 1].sum;
		t[i].lz = 0;
	}
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].sum = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].sum = t[i].r - t[i].l + 1 - t[i].sum;
		t[i].lz ^= 1;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r);
	if (r > mid) update(i << 1 | 1, l, r);
	push_up(i);
}

int query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].sum;
	push_down(i);
	int s = 0, mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

void add(int u, int v)
{
	e[++ cnt] = edge{v, head[u]};
	head[u] = cnt;
}

void dfs(int u)
{
	dfn[u] = ++ dfn_cnt;
	b[dfn[u]] = a[u];
	siz[u] = 1;
	for (int i = head[u]; i; i= e[i].next)
	{
		int v = e[i].to;
		dfs(v);
		siz[u] += siz[v];
	}
}


int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i ++ )
	{
		int p;scanf("%d", &p);
		add(p, i);
	}
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &a[i]);
	dfs(1);

	build(1, 1, n);
	int m;scanf("%d", &m);
	for (int i = 1; i <= m; i ++ )
	{
		
		int x;
		scanf("%s %d", str, &x);
		if (str[0] == 'g') printf("%d\n", query(1, dfn[x], dfn[x] + siz[x] - 1));
		else update(1, dfn[x], dfn[x] + siz[x] - 1); 
	}

	return 0;
}