#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50005;

int n, m;
int a[N];
struct T
{
	int l, r;
	int sum, lmx, rmx, mx;
}t[N << 2];

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
	t[i].lmx = max(t[i << 1].lmx, t[i << 1].sum + t[i << 1 | 1].lmx);
	t[i].rmx = max(t[i << 1 | 1].rmx, t[i << 1 | 1].sum + t[i << 1].rmx);
	t[i].mx = max(max(t[i << 1].mx, t[i << 1 | 1].mx), t[i << 1].rmx + t[i << 1 | 1].lmx);
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].mx = t[i].lmx = t[i].rmx = t[i].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

T query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i];
	int mid = (t[i].l + t[i].r) >> 1;
	if (l > mid) return query(i << 1 | 1, l, r);
	else if (r <= mid) return query(i << 1, l, r);
	else
	{
		T ans, ls, rs;
		ls = query(i << 1, l, r), rs = query(i << 1 | 1, l, r);
		ans.sum = ls.sum + rs.sum;
		ans.lmx = max(ls.lmx, ls.sum + rs.lmx);
		ans.rmx = max(rs.rmx, rs.sum + ls.rmx);
		ans.mx = max(max(ls.mx, rs.mx), ls.rmx + rs.lmx);
		return ans;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(1, l, r).mx);
	}
	return 0;
}