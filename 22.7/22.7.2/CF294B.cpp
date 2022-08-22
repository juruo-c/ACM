#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000;

int n, m;
int t[N], w[N];
int f[N];

int main()
{
	scanf("%d", &n);
	int sumw = 0;
	for (int i = 1; i <= n; i ++ ) scanf("%d%d", &t[i], &w[i]), m += t[i], sumw += w[i];

	memset(f, -1, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = m; j >= t[i]; j -- )
			if (f[j - t[i]] != -1)
				f[j] = max(f[j], f[j - t[i]] + w[i]);

	for (int i = 1; i <= m; i ++ )
		if (f[i] != -1 && sumw - f[i] <= i)
		{
			printf("%d\n", i);
			break;
		}

	return 0;
}