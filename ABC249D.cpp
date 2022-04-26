#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n;
int a[N], c[N];

int main()
{
	scanf("%d", &n);
	int mx = 0;
	for (int i = 1; i <= n; i ++ ) 
		scanf("%d", &a[i]), c[a[i]] ++, mx = max(mx, a[i]);

	long long ans = 0;
	for (int i = 1; i <= mx; i ++ )
		for (int j = 1; 1LL * i * j <= mx; j ++ )
			ans += 1LL * c[i] * c[j] * c[i * j];

	printf("%lld\n", ans);


	return 0;
}