#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100005;
const int mod = 998244353;

int n;
int c[N];

int main()
{
	int t;cin >> t;
	while (t -- )
	{
		cin >> n;
		int c1 = 0, p1 = 0;
		bool flag = true;
		for (int i = 0; i < n; i ++ )
		{
			cin >> c[i];
			if (c[i] == 1)
				c1 ++, p1 = i; 
		}

		if (c1 != 1)
		{
			cout << "NO" << endl;
			continue;
		}

		for (int i = 0; i < n; i ++ )
		{
			if (c[(p1 + 1) % n] > c[p1] + 1)
			{
				flag = false;
				break;
			}
			p1 = (p1 + 1) % n;

		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}