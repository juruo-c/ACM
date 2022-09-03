#include <iostream>

using namespace std;

int a[4];

int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		int x;
		cin >> x;
		for (int i = 1; i <= 3; i ++ )
			cin >> a[i];

		int cnt = 0;
		while (x)
		{
			x = a[x];
			cnt ++;
		}

		if (cnt == 3) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}