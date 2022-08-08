#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 500005, INF = 0x3f3f3f3f;

int n, m;
int a[N], b[N];
int pre[N], pos[N];
struct Ask
{
	int l, id;
};
vector<Ask> asks[N];
int ans[N];

struct T
{
	int l, r;
	int mi;
}t[N << 2];

void push_up(int i)
{
	t[i].mi = min(t[i << 1].mi, t[i << 1 | 1].mi);
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r) 
	{
		t[i].mi = INF;
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
		t[i].mi = k;
		return;
	}
	int mid = (t[i].l + t[i].r) >> 1;
	if (pos <= mid) update(i << 1, pos, k);
	else update(i << 1 | 1, pos, k);
	push_up(i);
}

int query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].mi;
	int mid = (t[i].l + t[i].r) >> 1;
	int mi = INF;
	if (l <= mid) mi = min(query(i << 1, l, r), mi);
	if (r > mid) mi = min(query(i << 1 | 1, l, r), mi);
	return mi;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int cnt = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; i ++ ) a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;

	for (int i = 1; i <= n; i ++ )
		pre[i] = pos[a[i]], pos[a[i]] = i;

	build(1, 1, n);

	for (int i = 1; i <= m; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		asks[r].push_back({l, i});
	}

	for (int i = 1; i <= n; i ++ )
	{
		if (pre[i]) update(1, pre[i], i - pre[i]);
		for (auto ask : asks[i])
			ans[ask.id] = query(1, ask.l, i);
	}
		
	for (int i = 1; i <= m; i ++ )
		printf("%d\n", ans[i] == INF ? -1 : ans[i]);

	return 0;
}