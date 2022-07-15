#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int r, s, p;
double f[N][N][N][3];

int main()
{
	scanf("%d%d%d", &r, &s, &p);
	
	for (int i = 1; i <= r; i ++ ) f[i][0][0][0] = 1;
	for (int i = 1; i <= s; i ++ ) f[0][i][0][1] = 1;
	for (int i = 1; i <= p; i ++ ) f[0][0][i][2] = 1;

	for (int i = 0; i <= r; i ++ )
		for (int j = 0; j <= s; j ++ )
			for (int k = 0; k <= p; k ++ )
			{
				if (j == 0 && i == 0 && k == 0) continue;
				if (j == 0 && k == 0 || i == 0 && j == 0 || i == 0 && k == 0) continue;
				double t = 1.0 / (i * j + i * k + j * k);
				if (j >= 1) 
				{
					f[i][j][k][0] += t * i * j * f[i][j - 1][k][0];
					f[i][j][k][1] += t * i * j * f[i][j - 1][k][1];
					f[i][j][k][2] += t * i * j * f[i][j - 1][k][2];
				}
				if (i >= 1) 
				{
					f[i][j][k][0] += t * i * k * f[i - 1][j][k][0];
					f[i][j][k][1] += t * i * k * f[i - 1][j][k][1];
					f[i][j][k][2] += t * i * k * f[i - 1][j][k][2];
				}
				if (k >= 1) 
				{
					f[i][j][k][0] += t * j * k * f[i][j][k - 1][0];
					f[i][j][k][1] += t * j * k * f[i][j][k - 1][1];
					f[i][j][k][2] += t * j * k * f[i][j][k - 1][2];
				}
			}

	printf("%.10f %.10f %.10f\n", f[r][s][p][0], f[r][s][p][1], f[r][s][p][2]);

	return 0;
}