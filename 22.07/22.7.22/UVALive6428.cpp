#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, p, b;
int a[105];
int ans[105];

int exgcd(int a, int b, int& x, int& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int t = x;
	x = y, y = t - y * (a / b);
	return d;
}

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	scanf("%d%d%d", &n, &p, &b);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), a[i] %= p;

	int g = a[1];
	ans[1] = 1;
	for (int i = 2; i <= n; i ++ )
	{
		int x, y;
		g = exgcd(g, a[i], x, y);
		for (int j = 1; j < i; j ++ )
			ans[j] = ans[j] * x % p;
		ans[i] = y;
	}

	int x, y;
	g = exgcd(g, p, x, y);
	for (int i = 1; i <= n; i ++ )
		ans[i] = ans[i] * x % p;

	if (b % g)
		puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= n; i ++ )
		{
			ans[i] = ans[i] * b / g % p;
			printf("%d ", (ans[i] + p) % p);
		}
	}

	return 0;
}