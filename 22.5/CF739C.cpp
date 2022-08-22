#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 300005;

int n, m;
int a[N];
struct T
{
	int l, r;
	int len, inc, dec, lans, rans, ans;
	LL lv, rv, lz;
}t[N << 2];

void push_up(int i)
{
	int ls = i << 1, rs = i << 1 | 1;
	t[i].lv = t[ls].lv, t[i].rv = t[rs].rv;
	t[i].inc = t[rs].inc;
	if (t[rs].inc == t[rs].len && t[ls].rv < t[rs].lv) t[i].inc += t[ls].inc;
	t[i].dec = t[ls].dec;
	if (t[ls].dec == t[ls].len && t[ls].rv > t[rs].lv) t[i].dec += t[rs].dec;

	t[i].lans = t[ls].lans;
	if (t[ls].inc == t[ls].len)
	{
		if (t[ls].rv < t[rs].lv) t[i].lans += t[rs].lans;
		if (t[ls].rv > t[rs].lv) t[i].lans += t[rs].dec;
	}
	else if (t[ls].lans == t[ls].len && t[ls].rv > t[rs].lv) t[i].lans += t[rs].dec;

	t[i].rans = t[rs].rans;
	if (t[rs].dec == t[rs].len)
	{
		if (t[rs].lv < t[ls].rv) t[i].rans += t[ls].rans;
		if (t[rs].lv > t[ls].rv) t[i].rans += t[ls].inc;
	}
	else if (t[rs].rans == t[rs].len && t[rs].lv > t[ls].rv) t[i].rans += t[ls].inc;

	t[i].ans = max(t[ls].ans, t[rs].ans);
	if (t[ls].rv < t[rs].lv) t[i].ans = max(t[i].ans, t[ls].inc + t[rs].lans);
	if (t[ls].rv > t[rs].lv) t[i].ans = max(t[i].ans, t[ls].rans + t[rs].dec);
}

void push_down(int i)
{
	if (t[i].lz)
	{
		t[i << 1].lz += t[i].lz;
		t[i << 1 | 1].lz += t[i].lz;
		t[i << 1].lv += t[i].lz;
		t[i << 1].rv += t[i].lz;
		t[i << 1 | 1].lv += t[i].lz;
		t[i << 1 | 1].rv += t[i].lz;
		t[i].lz = 0;
	}
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	t[i].len = r - l + 1;
	if (l == r)
	{
		t[i].lv = t[i].rv = a[l];
		t[i].inc = t[i].dec = t[i].lans = t[i].rans = t[i].ans = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build (i << 1, l, mid);
	build (i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r) 
	{
		t[i].lv += k;
		t[i].rv += k;
		t[i].lz += k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r )>> 1;
	if (l <= mid) update(i << 1, l, r, k);
	if (r > mid) update(i << 1 | 1, l, r, k);
	push_up(i);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	build(1, 1, n);

	scanf("%d", &m);
	for (int i = 1; i <= m; i ++ )
	{
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		update(1, l, r, d);
		printf("%d\n", t[1].ans);
	}
	return 0;
}