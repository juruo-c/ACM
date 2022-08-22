#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int cnt;
int factor[N];

void getfactor(int n)
{
	for (int i = 2; i * i <= n; i ++ )
	{
		if (n % i == 0)
		{
			factor[++ cnt] = i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n != 1) factor[++ cnt] = n;
}

LL calc(LL m)
{
	LL res = 0;
	for (int i = 1; i < 1 << cnt; i ++ )
	{
		LL t = 1;
		bool flag = 0;
		for (int j = 0; j < cnt; j ++ )
			if (i & (1 << j)) 
			{
				t *= factor[j + 1];
				flag ^= 1;
			}
		if (flag) res += m / t;
		else res -= m / t;
	}
	return m - res;
}

int main()
{
	int t, n;
	cin >> t;
	LL a, b;
	int kase = 0;
	while (t --)
	{
		cin >> a >> b >> n;
		cnt = 0;
		getfactor(n);
		cout << "Case #" << ++ kase << ": ";
		cout << calc(b) - calc(a - 1) << endl;
	}
	return 0;
}