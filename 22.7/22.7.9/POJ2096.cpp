#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005;

int n, s;
double f[N][N];

int main()
{
	scanf("%d%d", &n, &s);
	for (int i = n; i >= 0; i -- )
		for (int j = s; j >= 0; j -- )
		{
			if (i == n && j == s) continue;
			f[i][j] = (f[i][j + 1] * i * (s - j) + f[i + 1][j] * (n - i) * j + f[i + 1][j + 1] * (n - i) * (s - j) + n * s) / (n * s - i * j);
		}
	printf("%.10f\n", f[0][0]);

	return 0;
}