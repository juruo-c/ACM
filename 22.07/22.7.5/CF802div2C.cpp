#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200005;

int n;
int a[N];
LL c[N];

int main()
{
	int t;scanf("%d", &t);
	while(t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), c[i] = a[i] - a[i - 1];

		LL ans = 0;
		for (int i = 2; i <= n; i ++ )
		{
			if (c[i] >= 0) ans += c[i];
			else 
			{
				ans -= c[i];
				c[1] += c[i];
			}
		}
		
		printf("%lld\n", ans + abs(c[1]));

	}
	return 0;
}