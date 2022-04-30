#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 200005, M = 1000005, mod = 1000000007;

int n, m;
int a[N], s[N];
int c[M];
int ans[N];
int p[M];
int last[M];
bool vis[M];

struct Ask
{
	int l, r;
	int id;
	bool operator < ( const Ask& a ) const
	{
		return r < a.r;
	}
}ask[N];

void prime()
{
	for (int i = 2; i < M; i ++ )
	{
		if (!vis[i])
			p[++ p[0]] = i;
		for (int j = 1; j <= p[0] && 1LL * i * p[j] < M; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int qpow(int a, int b)
{
	int res = 1;
	while(b)
	{
		if (b & 1) res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return res;
}

void update(int x, int k)
{
	for (int i = x; i < M; i += (i & -i)) 
		c[i] = 1LL * c[i] * k % mod;
}

int query(int x)
{
	int res = 1;
	for (int i = x; i; i -= (i & -i))
		res = 1LL * res * c[i] % mod;
	return res;
}

void solve(int x)
{
	int t = a[x];
	for (int i = 1; p[i] * p[i] <= t; i ++ )
	{
		if (t % p[i]) continue;
		update(x, 1LL * (p[i] - 1) * qpow(p[i], mod - 2) % mod);
		if (last[p[i]]) update(last[p[i]], 1LL * p[i] * qpow(p[i] - 1, mod - 2) % mod);
		last[p[i]] = x;
		while (t % p[i] == 0) t /= p[i];
	}
	if (t > 1)
	{
		update(x, 1LL * (t - 1) * qpow(t, mod - 2) % mod);
		if (last[t]) update(last[t], 1LL * t * qpow(t - 1, mod - 2) % mod);
		last[t] = x;
	}
}

int main()
{
	prime();
	scanf("%d", &n);
	for (int i = 0; i < M; i ++ ) c[i] = 1;
	s[0] = 1;
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), s[i] = 1LL * s[i - 1] * a[i] % mod;
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++ )
		scanf("%d%d", &ask[i].l, &ask[i].r), ask[i].id = i;
	sort(ask + 1, ask + 1 + m);

	int cur = 1;
	for (int i = 1; i <= m; i ++ )
	{
		int l = ask[i].l, r = ask[i].r;
		while (cur <= r)
		{
			solve(cur);
			cur ++;
		}
		ans[ask[i].id] = 1LL * s[r] * qpow(s[l - 1], mod - 2) % mod * query(r) % mod * qpow(query(l - 1), mod - 2) % mod;
	}

	for (int i = 1; i <= m; i ++ ) printf("%d\n", ans[i]);
	return 0;
}