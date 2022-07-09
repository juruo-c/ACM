#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 205;

int n;
double p[N][N];
double f[10][N];

int main()
{
	while (~scanf("%d", &n) && n != -1)
	{
		for (int i = 0; i < 1 << n; i ++ )
			for (int j = 0; j < 1 << n; j ++ )
				scanf("%lf", &p[i][j]);

		memset(f, 0, sizeof f);
		for (int i = 0; i < 1 << n; i ++ ) f[0][i] = 1;

		for (int i = 1; i <= n; i ++ )
		{
			int t = 1 << (i - 1);
			int tt = 1 << i;
			for (int j = 0; j < 1 << n; j ++ )
			{
				int l = j / tt * tt, r;	
				if (j < l + t) l += t;
				r = l + t - 1;
				// cout << "i = " << i << " j = " << j << " l = " << l << " r = " << r << endl;
				for (int k = l; k <= r; k ++ )
				{
					f[i][j] += p[j][k] * f[i - 1][k];
				}
				f[i][j] *= f[i - 1][j];
			}
		}

		double mx = 0;
		int id = -1;
		for (int i = 0; i < 1 << n; i ++ )
			if (f[n][i] > mx)
			{
				id = i + 1;
				mx = f[n][i];
			}

		printf("%d\n", id);

	}
	return 0;
}