#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105, M = 1 << 15;

int k, n;
int need[20];
int p[20];
double f[N][M];

int main()
{
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i ++ )
	{
		scanf("%d", &p[i]);
		int x;
		while (scanf("%d", &x) && x)
			need[i] |= (1 << (x - 1));
	}

	for (int i = k; i >= 1; i -- )
		for (int j = 0; j < (1 << n); j ++ )
		{
			for (int s = 0; s < n; s ++ )
			{
				if ((j & need[s]) == need[s]) 
					f[i][j] += max(f[i + 1][j], f[i + 1][j | (1 << s)] + p[s]);
				else f[i][j] += f[i + 1][j];
			}
			f[i][j] /= n;
		}

	printf("%.6f\n", f[1][0]);

	return 0;
}