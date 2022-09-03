#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n, q, m = 200000 + 64;
int a[N];
struct T
{
	int l, r;
	int sum, lz;
}t[N << 2];

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void push_down(int i)
{
	if (t[i].lz != -1)
	{
		t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
		t[i << 1].sum = t[i].lz * (t[i << 1].r - t[i << 1].l + 1);
		t[i << 1 | 1].sum = t[i].lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1);
		t[i].lz = -1;
	}
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	t[i].lz = -1;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update(int i, int pos, int k)
{
	if (t[i].l == t[i].r)
	{
		t[i].sum = t[i].lz = k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (pos <= mid) update(i << 1, pos, k);
	else update(i << 1 | 1, pos, k);
	push_up(i);
}

void update(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].sum = k * (t[i].r - t[i].l + 1);
		t[i].lz = k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r, k);
	if (r > mid) update(i << 1 | 1, l, r, k);
	push_up(i);	
}

int query(int i, int pos)
{
	if (t[i].l == t[i].r)
		return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (pos <= mid) return query(i << 1, pos);
	else return query(i << 1 | 1, pos);
}

int query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
		return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	int s = 0;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

void Add(int x)
{
	if (!query(1, x)) update(1, x, 1);
	else
	{
		int l = x, r = m;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (query(1, x, mid) == mid - x + 1) l = mid;
			else r = mid - 1;
		}
		update(1, l + 1, 1);
		update(1, x, l, 0);
	}	
}

void Sub(int x)
{
	if (query(1, x)) update(1, x, 0);
	else
	{
		int l = x, r = m;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (query(1, x, mid)) r = mid;
			else l = mid + 1;
		}
		update(1, l, 0);
		update(1, x, l - 1, 1);
	}
}

int Query()
{
	int sum = query(1, 1, m);
	int l = 1, r = m;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (query(1, 1, mid) == sum) r = mid;
		else l = mid + 1;
	}
	return r;
}

int main()
{	
	scanf("%d%d", &n, &q);
	build(1, 1, m);
	for (int i = 1; i <= n; i ++ )
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		Add(x);
	}

	for (int i = 1; i <= q; i ++ )
	{
		int k, l;
		scanf("%d%d", &k, &l);
		Sub(a[k]);
		a[k] = l;
		Add(a[k]);
		printf("%d\n", Query());
	}

	return 0;
}