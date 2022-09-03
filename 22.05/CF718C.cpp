#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100005, mod = 1000000007;

int n, m;
int a[N];

struct Matrix
{
	int m[2][2];
	Matrix(){memset(m, 0, sizeof m);}
	void init(){
		for (int i = 0; i < 2; i ++ )
			m[i][i] = 1;
	}

	void clear()
	{
		memset(m, 0, sizeof m);
	}

	bool empty()
	{
		for (int i = 0; i < 2; i ++ ) 
			for (int j = 0; j < 2; j ++ )
				if (m[i][j]) return false;
		return true;
	}

	Matrix operator * (const Matrix& b) const
	{
		Matrix res;
		for (int i = 0; i < 2; i ++ )
			for (int j = 0; j < 2; j ++ )
				for (int k = 0; k < 2; k ++ )
					res.m[i][j] = (res.m[i][j] + 1LL * m[i][k] * b.m[k][j] % mod) % mod;
		return res;
	}

	Matrix operator + (const Matrix& b) const
	{
		Matrix res;
		for (int i = 0; i < 2; i ++ )
			for (int j = 0; j < 2; j ++ )
				res.m[i][j] = (m[i][j] + b.m[i][j]) % mod;
		return res;
	}
};

Matrix Base;

struct T
{
	int l, r;
	Matrix sum, lz;
}t[N << 2];

Matrix qpow(Matrix a, int b)
{
	Matrix res;
	res.init();
	while (b)
	{
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void build(int i, int l, int r)
{
	t[i].lz.init();
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].sum = qpow(Base, a[l] - 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void push_down(int i)
{
	if (!t[i].lz.empty())
	{
		t[i << 1].lz = t[i << 1].lz * t[i].lz;
		t[i << 1 | 1].lz = t[i << 1 | 1].lz * t[i].lz;
		t[i << 1].sum = t[i << 1].sum * t[i].lz;
		t[i << 1 | 1].sum = t[i << 1 | 1].sum * t[i].lz;
		t[i].lz.clear();
		t[i].lz.init();
	}
}

void update(int i, int l, int r, Matrix k)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].lz = t[i].lz * k;
		t[i].sum = t[i].sum * k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r, k);
	if (r > mid) update(i << 1 | 1, l, r, k);
	push_up(i);
}

Matrix query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r ) >> 1;
	Matrix s;
	if (l <= mid) s = s + query(i << 1, l, r);
	if (r > mid) s = s + query(i << 1 | 1, l, r);
	return s;
}

int main()
{
	Base.m[0][0] = Base.m[0][1] = Base.m[1][0] = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	build(1, 1, n);

	for (int i = 1; i <= m; i ++ )
	{
		int op, l, r, x;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1)
		{
			scanf("%d", &x);
			update(1, l, r, qpow(Base, x));
		}
		else
			printf("%d\n", query(1, l, r).m[0][0]);
	}
	return 0;
}