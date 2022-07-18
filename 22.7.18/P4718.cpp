#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 1000005;

int n;
LL X, Y;
LL fac_cnt;
LL prime_fac[N];
LL a[N];

LL qmul(LL a, LL b, LL p)
{
	LL z = (long double)a / p * b;
	LL res = (ULL) a * b - (ULL)z * p;
	return (res + p) % p;
}

LL qpow(LL a, LL b, LL p)
{
	LL res = 1;
	while (b)
	{
		if (b & 1) res = qmul(res, a, p);
		b >>= 1;
		a = qmul(a, a, p);
	}
	return res;
}

bool Miller_Rabin(LL n)
{
	if (n == 2) return true;
	if (n < 2 || !(n & 1)) return false;
	LL m = n - 1, k = 0;
	while (!(m & 1)) m >>= 1, k ++;
	for (int i = 1; i <= 6; i ++ )
	{
		LL a = rand() % (n - 1) + 1;
		LL x = qpow(a, m, n), y;
		for (int j = 1; j <= k; j ++ )
		{
			y = qmul(x, x, n);
			if (y == 1 && x != 1 && x != n - 1)
				return false;
			x = y;
		}
		if (y != 1) return false;
	}
	return true;
}

LL gcd(LL a, LL b)
{
	return !b ? a : gcd(b, a % b);
}

LL Pollard_Rho(LL n)
{
	LL z, x, y, g, c;
	while(true)
	{
		int i = 0, j = 1;
		c = rand() % (n - 1) + 1;
		z = 1;
		while (++ i)
		{
			x = (qmul(x, x, n) + c) % n;
			z = qmul(z, abs(x - y), n);
			if (!z || x == y) break;
			if (i == j || i % 127 == 0)
			{
				g = gcd(n, z);
				if (g > 1) return g;
				if (i == j) j <<= 1, y = x;
			}
		}
	}
}

void getfactor(LL n)
{
	if (n == 1) return ;
	if (Miller_Rabin(n))
	{
		prime_fac[++ fac_cnt] = n;
		return;
	}
	LL a = Pollard_Rho(n);
	while (n % a == 0) n /= a;
	getfactor(a);
	getfactor(n);
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

LL cal(LL n, LL x)
{
	LL ans = 0;
	while (n % x == 0)
	{
		ans ++;
		n /= x;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		LL n;
		fac_cnt = 0;
		cin >> n;
		if (Miller_Rabin(n)) cout << "Prime" << endl;
		else
		{
			getfactor(n);
			LL ans = 0;
			for (int i = 1; i <= fac_cnt; i ++ )
				ans = max(ans, prime_fac[i]);
			cout << ans << endl;
		}
	}
	return 0;
}