#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000005, M = 10005;

double P;
int n, V;
int m[N];
double p[N];
double f[N];

int main()
{
	int t;scanf("%d", &t);
	while (t --)
	{
		V = 0;
		scanf("%lf%d", &P, &n);
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%d%lf", &m[i], &p[i]);
			V += m[i];
		}

		memset(f, 0, sizeof f);
		f[0] = 1;
		for (int i = 1; i <= n; i ++ )
			for (int j = V; j >= m[i]; j -- )
				f[j] = max(f[j], f[j - m[i]] * (1 - p[i]));

		for (int i = V; i >= 0; i -- )
			if (1 - f[i] <= P)
			{
				printf("%d\n", i);
				break;
			}

	}
	return 0;
}