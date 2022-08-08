#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 200005;

int n, m;
int a[N];
struct T
{
	int l, r;
	double Cos, Sin;
	LL lz;
}t[N << 2];

void push_up(int i)
{
	t[i].Cos = t[i << 1].Cos + t[i << 1 | 1].Cos;
	t[i].Sin = t[i << 1].Sin + t[i << 1 | 1].Sin;
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].Cos = cos(a[l]);
		t[i].Sin = sin(a[l]);
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
		LL lz = t[i].lz;
		t[i << 1].lz += lz;
		t[i << 1 | 1].lz += lz;
		double Sin = t[i << 1].Sin, Cos = t[i << 1].Cos;
		t[i << 1].Sin = Sin * cos(lz) + Cos * sin(lz);
		t[i << 1].Cos = Cos * cos(lz) - Sin * sin(lz);
		Sin = t[i << 1 | 1].Sin, Cos = t[i << 1 | 1].Cos;
		t[i << 1 | 1].Sin = Sin * cos(lz) + Cos * sin(lz);
		t[i << 1 | 1].Cos = Cos * cos(lz) - Sin * sin(lz);	
		t[i].lz = 0;
	}
}

void update(int i, int l, int r, int v)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		double Sin = t[i].Sin, Cos = t[i].Cos;
		t[i].Sin = Sin * cos(v) + Cos * sin(v);
		t[i].Cos = Cos * cos(v) - Sin * sin(v);
		t[i].lz += v;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r, v);
	if (r > mid) update(i << 1 | 1, l, r, v);
	push_up(i);
}

double query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
		return t[i].Sin;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	double s = 0;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++ )
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1)
		{
			int v;
			scanf("%d", &v);
			update(1, l, r, v);
		}
		else 
			printf("%.1f\n", query(1, l, r));
	}
	return 0;
}

