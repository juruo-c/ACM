#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

typedef long long LL;

const int N = 1000005;

int n;
LL X, Y;
LL fac_cnt;
LL prime_fac[N];
LL a[N];


LL qmul(LL a, LL b, LL p)
{
	LL c = (long double) a * b / p;
	long double ans = a * b - c * p;
	if (ans < 0) ans += p;
	else if(ans >= p) ans -= p;
	return ans;
}

LL qpow(LL a, LL b, LL p)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

const LL prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};
bool Miller_Rabin(LL p)
{
	if (p == 2) return true;
	if (p < 2 || !(p & 1)) return false;
	LL s = 0, t = p - 1;
	while (!(t & 1)) s ++, t >>= 1;
	for (int i = 0; i < 10 && prime[i] < p; i ++ )
	{
		LL a = prime[i];
		LL x = qpow(a, t, p);
		for (int j = 0; j < s; j ++ )
		{
			LL y = qmul(x, x, p);
			if (y == 1 && x != 1 && x != p - 1) return false;
			x = y;
		}
		if (x != 1) return false;
	}
	return true;
}

LL gcd(LL a, LL b)
{
	return !b ? a : gcd(b, a % b);
}

LL Pollard_Rho(LL p)
{
	LL s = 0, t = 0, c = 1LL * rand() % (p - 1) + 1;
	for (LL g = 1, val = 1, d; ; g <<= 1, s = t, val = 1)
	{
		for (LL j = 0; j < g; j ++ )
		{
			t = (qmul(t, t, p) + c) % p;
			val = qmul(val, abs(t - s), p);
			if (j % 127 == 0 && (d = gcd(p, val)) > 1)
				return d;
		}
		d = gcd(p, val);
		if (d > 1) return d;
	}
	return p;
}

void solve(LL n)
{
	if (n < 2) return;
	if (Miller_Rabin(n))
	{
		prime_fac[++ fac_cnt] = n;
		return;
	}
	LL d = 0;
	while ((d = Pollard_Rho(n)) >= n);
	while (n % d == 0) n /= d;
	solve(n);
	solve(d);
}

LL calc(LL n, LL x)
{
	LL ans = 0;
	while (n)
	{
		ans += n / x;
		n /= x;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%lld%lld", &n, &X, &Y);
		for (int i = 1; i <= n; i ++ )
			scanf("%lld", &a[i]);

		fac_cnt = 0;
		solve(X);
		LL ans = 1e18;
		map<LL, LL> cnt;
		for (int i = 1; i <= fac_cnt; i ++ )
			cnt[prime_fac[i]] ++;
		auto it = cnt.begin();
		while (it != cnt.end())
		{
			LL s = 0;
			for (int i = 1; i <= n; i ++ )
				s += calc(a[i], it->first);
			ans = min(ans, (calc(Y, it->first) - s) / it->second);
			it ++;
		}
		printf("%lld\n", ans);
	}	
	return 0;
}