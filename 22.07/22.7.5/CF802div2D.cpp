#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 200005;

int v[N];
int n, q;

int main()
{
	scanf("%d", &n);
	LL sum = 0, mxt = 0;
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d", &v[i]);
		sum += v[i];
		mxt = max(mxt, (sum + i - 1) / i);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++ )
	{
		int t;
		scanf("%d", &t);
		if (t < mxt) puts("-1");
		else printf("%d\n", (sum + t - 1) / t);
	}
	
	return 0;
}