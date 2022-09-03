#include <iostream>

using namespace std;

int n, m;

int main()
{
	int t;cin >> t;
	while (t --)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j <= m; j ++ )
			{
				if (j > 1) cout << " " ;
				if ((j % 4 == 0 || j % 4 == 1))
				{
					if (i % 4 == 0 || i % 4 == 1) cout << 0;
					else cout << 1;
				} 
				else
				{
					if (i % 4 == 0 || i % 4 == 1) cout << 1;
					else cout << 0;
				}
			}
			cout << endl;
		}
	}
	return 0;
}