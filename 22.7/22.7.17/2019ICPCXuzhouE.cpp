#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const int N = 100005;

LL x, y, a[N];
LL max_factor;

struct BigIntegerFactor
{
	const static int N = 1000005;
	LL prime[N], p[N], fac[N], sz, cnt; //多组数据记得初始化cnt=0
	LL qmul(LL a, LL b, LL p) //wa了改为龟速乘或者__int128
	{
		if (p <= 1000000000)
			return a * b % p;
		return (a * b - (LL)((long double) a / p * b + 1e-8) * p + p) % p;
	}

	void init(int n)
	{
		int tot = 0;
		sz = n - 1;
		for (int i = 1; i <= sz; i ++)
			p[i] = i;
		for (int i = 2; i <= sz; i ++ )
		{
			if (p[i] == i)
				prime[tot ++] = i;
			for (int j = 0; j < tot && 1LL * i * prime[j] <= sz; j ++ )
			{
				p[i * prime[j]] = prime[j];
				if (i % prime[j] == 0)
					break;
			}
		}
	}

	LL qpow(LL a, LL b, LL p)
	{
		LL res = 1;
		while (b)
		{
			if (b & 1) res = qmul(res, a, p);
			a = qmul(a, a, p);
			b >>= 1;
		}
		return res;
	}

	bool check(LL a, LL n)
	{
		LL t = 0, u = n - 1;
		while (!(u & 1)) t ++, u >>= 1;
		LL x = qpow(a, u, n), y = 0;
		while (t --)
		{
			y = qmul(x, x, n);
			if (y == 1 && x != 1 && x != n - 1)
				return false;
			x = y;
		}
		return y == 1;
	}

	bool Miller_Rabin(LL n, int k)
	{
		if (n == 2)
			return true;
		if (n < 2 || !(n & 1)) return false;
		if (n <= sz) return p[n] == n;
		for (int i = 0; i <= k; i ++ )
		{
			if (!check(rand() % (n - 1) + 1, n))
				return false;
		}
		return true;
	}

	inline LL gcd(LL a, LL b)
	{
		return !b ? a : gcd(b, a % b);
	}

	inline LL Abs(LL x)
	{
		return x < 0 ? -x : x;
	}

	LL Pollard_Rho(LL n)
	{
		LL s = 0, t = 0, c = rand() % (n - 1) + 1, v = 1, ed = 1;
		while (true)
		{
			for (int i = 1; i <= ed; i ++ )
			{
				t = (qmul(t, t, n) + c) % n;
				v = qmul(v, Abs(t - s), n);
				if (i % 127 == 0)
				{
					LL d = gcd(v, n);
					if (d > 1)
						return d;
				}
			}
			LL d = gcd(v, n);
			if (d > 1) return d;
			s = t, v = 1, ed <<= 1;
		}
	}

	void getfactor(LL n)
	{
		if (n <= sz)
		{
			while (n != 1)
				fac[cnt ++ ] = p[n], n /= p[n];
			max_factor = max_factor > p[n] ? max_factor : p[n];
			return;
		}
		if (Miller_Rabin(n, 6))
		{
			fac[cnt ++] = n;
			max_factor = max_factor > n ? max_factor : n;
		}
		else
		{
			LL d = n;
			while (d >= n)
				d = Pollard_Rho(n);
			getfactor(d);
			getfactor(n / d);
		}
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

	LL solve(int n, LL x, LL y)
	{
		map<LL, LL> mp;
		LL ans = 1e18;
		cnt = 0;
		getfactor(x);
		for(int i = 0; i < cnt; i ++ )
			mp[fac[i]] ++;
		for (auto it = mp.begin(); it != mp.end(); it ++)
		{
			LL num = 0;
			for (int i = 1; i <= n; i ++ )
				num += calc(a[i], it->first);
			ans = min(ans, (calc(y, it->first) - num) / it->second);
		}
		return ans;
	}
}Q;

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%lld%lld", &n, &x, &y);
		for (int i = 1; i <= n; i ++ )
			scanf("%lld", &a[i]);
		printf("%lld\n", Q.solve(n, x, y));
	}
	return 0;
}