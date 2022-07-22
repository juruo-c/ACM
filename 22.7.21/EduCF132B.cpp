#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
int a[N];
int c1[N], c2[N];
LL s1[N], s2[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &a[i]);

	for (int i = 2; i <= n; i ++ )
		c1[i] = abs(min(0, a[i] - a[i - 1]));
	for (int i = n - 1; i >= 1; i -- )
		c2[i] = abs(min(0, a[i] - a[i + 1]));

	for (int i = 2; i <= n; i ++ )
		s1[i] = s1[i - 1] + c1[i];
	for (int i = n - 1; i >= 1; i -- )
		s2[i] = s2[i + 1] + c2[i];

	for (int i = 1; i <= m; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l < r)
			printf("%lld\n", s1[r] - s1[l]);
		else
			printf("%lld\n", s2[r] - s2[l]);
	}

	return 0;	
}