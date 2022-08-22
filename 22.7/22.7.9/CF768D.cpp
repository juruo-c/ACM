#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005, M = 10005;

int k, q;
double f[M][N];

int main()
{
	cin >> k >> q;
	f[0][0] = 1;
	for (int i = 1; i < M; i ++ )
		for (int j = 1; j <= k; j ++ )
			f[i][j] = f[i - 1][j] * j / k + f[i - 1][j - 1] * (k - j + 1) / k;

	for (int i = 1; i <= q; i ++ )
	{
		int p;scanf("%d", &p);
		for (int j = 1; j < M; j ++ )
			if (f[j][k] >= 1.0 * p / 2000)
			{
				printf("%d\n", j);
				break;
			}
	}

	return 0;
}