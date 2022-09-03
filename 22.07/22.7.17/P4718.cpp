#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const LL prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};
LL ans;

LL qmul(LL a, LL b, LL p)
{
	LL c = (long double) a * b / p;
	long double ans = a * b - c * p;
	if (ans < 0) ans += p;
	else if(ans >= p) ans -= p;
	return ans;
}

LL qpow(LL x, LL b, LL p)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = qmul(ans, x, p);
		x = qmul(x, x, p);
		b >>= 1;
	}
	return ans;
}

bool Miller_Rabin(LL p)
{
	if (p == 2) return true;
	if (p < 2 || !(p & 1)) return false;
	LL t = p - 1, s = 0;
	while (!(t & 1)) t >>= 1, s ++;
	for (int i = 0; i < 10 && prime[i] < p; i ++ )
	{
		LL x = qpow(prime[i], t, p), y;
		for (int j = 0; j < s; j ++ )
		{
			y = qmul(x, x, p);
			if (y == 1 && x != 1 && x != p - 1)
				return false;
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
	if (n < ans || n < 2) return;
	if (Miller_Rabin(n)) 
	{
		ans = n;
		return;
	}
	LL d = 0;
	while ((d = Pollard_Rho(n)) >= n);
	while (n % d == 0) n /= d;
	solve(n);
	solve(d);
}

int main()
{
	srand(998244353);
	int T;
	scanf("%d", &T);
	LL n;
	while (T --)
	{
		scanf("%lld", &n);
		if (Miller_Rabin(n))
		{
			printf("Prime\n");
			continue;
		}
		ans = 0;
		solve(n);
		printf("%lld\n", ans);
	}
	return 0;
}