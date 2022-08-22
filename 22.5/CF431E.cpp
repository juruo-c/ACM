#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005, M = 40 * N;

int n, m;
int ls[M], rs[M], num[M];
LL sum[M];
int h[N];
int rt, cnt;

void push_up(int i)
{
	sum[i] = sum[ls[i]] + sum[rs[i]];
	num[i] = num[ls[i]] + num[rs[i]];
}

void update(int& i, int l, int r, int pos, int k)
{
	if (!i) i = ++ cnt;
	if (l == r)
	{
		num[i] += k;
		sum[i] += pos * k;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(ls[i], l, mid, pos, k);
	else update(rs[i], mid + 1, r, pos, k);
	push_up(i);
}

double query(int i, int l, int r, LL Num, LL Sum, LL v)
{
	if (!i || l == r) 
		return (double)(v + Sum + sum[i]) / (Num + num[i]);
	int mid = (l + r) >> 1;
	if (1LL * (mid + 1) * (Num + num[ls[i]]) - (Sum + sum[ls[i]]) >= v) return query(ls[i], l, mid, Num, Sum, v);
	else return query(rs[i], mid + 1, r, Num + num[ls[i]], Sum + sum[ls[i]], v);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &h[i]), update(rt, 0, 1e9, h[i], 1);

	while(m --)
	{
		int op;
		scanf("%d", &op);
		int p, x;LL v;
		if (op == 1)
		{
			scanf("%d%d", &p, &x);
			update(rt, 0, 1e9, h[p], -1);
			update(rt, 0, 1e9, x, 1);
			h[p] = x;
		}
		else
		{
			scanf("%lld", &v);
			printf("%.5f\n", query(rt, 0, 1e9, 0, 0, v));
		}
	}
	return 0;
}