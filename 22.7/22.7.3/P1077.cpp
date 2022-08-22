#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105, mod = 1000007;

int n, m;
int a[N];
int f[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

	f[0] = 1;
	for (int i = 1; i <= n; i ++ )
		for (int j = m; j >= 0; j -- )
			for (int k = 1; k <= a[i] && k <= j; k ++ )
				f[j] = (f[j] + f[j - k]) % mod;
	printf("%d\n", f[m]);

	return 0;
}