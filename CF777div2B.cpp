#include <iostream>

using namespace std;

const int N = 105;

char g[N][N];

int main()
{
	int t;cin >> t;
	while (t --)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i ++ ) cin >> g[i];

		bool flag = true;
		for (int i = 0; i < n - 1; i ++ )
			for (int j = 0;j < m - 1; j ++ )
			{
				int s = g[i][j] - '0' + g[i][j + 1] - '0' + g[i + 1][j] - '0' + g[i + 1][j + 1] - '0';
				if (s == 3)
				{
					flag = false;
					break;
				}
			}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}