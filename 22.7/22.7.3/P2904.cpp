#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2505;

int n, m;
int sum[N];
int f[N];

int main()
{
	scanf("%d%d", &n, &m);
	sum[0] = 2 * m;
	for (int i = 1; i <= n; i ++ ) scanf("%d", &sum[i]), sum[i] += sum[i - 1];

	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < i; j ++ )
			f[i] = min(f[i], f[j] + sum[i - j]);

	printf("%d\n", f[n] - m);

	return 0;
}