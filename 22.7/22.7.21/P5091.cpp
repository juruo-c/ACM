#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20000005;

char b[N];

int getphi(int n)
{
	int ans = n;
	int t = n;
	for (int i = 2; i * i <= n; i ++ )
	{
		if (t % i == 0)
		{
			ans = ans - ans / i;
			while (t % i == 0)
				t /= i;
		}
	}
	if (t > 1) ans = ans - ans / t;
	return ans;
}

int qpow(int a, int b, int p)
{
	int ans = 1;
	while (b)
	{
		if (b & 1) ans = 1LL * ans * a % p;
		a = 1LL * a * a % p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int a, m;
	cin >> a >> m >> b + 1;
	int len = strlen(b + 1);
	int phi_m = getphi(m);

	bool flag = false;
	int c = 0;
	for (int i = 1; i <= len; i ++ )
	{	
		c = c * 10 + (b[i] - '0');
		if (c >= phi_m)
			flag = true, c %= phi_m;
	}

	if (flag) c += phi_m;

	cout << qpow(a, c, m);
	return 0;
}