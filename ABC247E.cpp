#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200005;

typedef long long LL;

int n;
int a[N];
int x, y;

LL solve(int L, int R)
{
	LL res = 0;
	int cx = 0, cy = 0;
	for (int l = L, r = L; l <= R; l ++ )
	{
		while (r <= R && (cx < 1 || cy < 1))
		{
			if (a[r] == x) cx ++;
			if (a[r] == y) cy ++;
			r ++;
		}
		if (cx >= 1 && cy >= 1) res += R - r + 2;
		if (a[l] == x) cx --;
		if (a[l] == y) cy --;
	}
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &a[i]);

	int last = 1;
	LL ans = 0;
	for (int i = 1; i <= n; i ++ )
		if (a[i] > x || a[i] < y)
		{
			if (last <= i - 1)
				ans += solve(last, i - 1);
			last = i + 1;
		}
	if (last <= n) ans += solve(last, n);

	printf("%lld", ans);

	return 0;
}