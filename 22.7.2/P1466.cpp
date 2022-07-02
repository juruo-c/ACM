#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 40, M = 1000;

int n;
long long f[M];

int main()
{
	scanf("%d", &n);
	int t = n * (n + 1) / 2;
	if (t % 2) puts("0");
	else
	{
		t /= 2;
		f[0] = 1;
		for (int i = 1; i <= n; i ++ )
			for (int j = t; j >= i; j -- )
				f[j] += f[j - i];

		printf("%lld\n", f[t] / 2);
	}
	return 0;
}