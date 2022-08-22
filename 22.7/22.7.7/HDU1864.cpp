#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35, M = 5000005;

int n;
int cnt;
int price[N];
bool f[M];

int main()
{
	double p;
	while (scanf("%lf%d", &p, &n) && n)
	{
		int m = p * 100;
		cnt = 0;
		for (int i = 1; i <= n; i ++ )
		{
			int c;
			scanf("%d", &c);
			bool flag = true;
			double sum = 0;
			double A = 0, B = 0, C = 0;
			for (int j = 0; j < c; j ++ )
			{
				char type;
				double pj;
				scanf(" %c:%lf", &type, &pj);
				sum += pj;
				if (type != 'A' && type != 'B' && type != 'C') flag = false;
				if (type == 'A') A += pj;
				else if(type == 'B') B += pj;
				else C += pj;

			}
			if (A <= 600 && B <= 600 && C <= 600 && sum <= 1000 && flag)
			{
				price[++ cnt] = sum * 100;
			}
		}


		memset(f, false, sizeof f);
		f[0] = true;
		// for (int i = 1; i <= cnt; i ++ )
		// 	cout << price[i] << endl;
		for (int i = 1; i <= cnt; i ++ )
			for (int j = m; j >= price[i]; j -- )
				f[j] |= f[j - price[i]];

		for (int i = m; i >= 0; i -- )
			if (f[i])
			{
				printf("%.2f\n", i * 1.0 / 100);
				break;
			}
	}
	return 0;
}