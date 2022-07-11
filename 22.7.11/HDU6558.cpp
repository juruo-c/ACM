#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1050;

double p;
double f[N];


int main()
{
	int t, kase = 0;
	scanf("%d", &t);
	while (t --)
	{
		memset(f, 0, sizeof f);
		scanf("%lf", &p);
		p = 1.0 * p / 100;
		f[1000] = 1 / p;
		for (int i = 999; i >= 20; i -- )
		{
			double pi = 1.0 * i / 1000;
			f[i] = p * (pi + (1 - pi) * (f[min(i + 20, 1000)] + 1)) + (1 - p) * (f[min(i + 15, 1000)] + 1);
		}

		printf("Case %d: %.10f\n", ++kase, f[20]);
	}
	return 0;
}