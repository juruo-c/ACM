#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long LL;

const int N = 100005;

int a[N];

int main()
{
	#ifdef ZYCMH
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif 

	int t;
	scanf("%d", &t);
	while(t --)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		printf("%d\n", a[n] + a[n - 1] - a[1] - a[2]);
	}

	return 0;
}