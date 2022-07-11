#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, t;
double p;
double f[2005][2005];

int main()
{
	scanf("%d%lf%d", &n, &p, &t);

	f[1][0] = 1 - p, f[1][1] = p;
	for (int i = 1; i <= t; i ++ )
	{
		for (int j = 0; j < n; j ++ )
		{
			f[i + 1][j + 1] += f[i][j] * p;
			f[i + 1][j] += f[i][j] * (1 - p);
		}
		f[i + 1][n] += f[i][n];
	}

	double ans = 0;
	for (int i = 1; i <= n; i ++ ) ans += i * f[t][i];
	printf("%.10f\n", ans);

	return 0;
}