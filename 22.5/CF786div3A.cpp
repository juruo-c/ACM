#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;cin >> T;
	while (T --)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) cout << 0 << " " << 0 << endl;
		else
		{
			if (y % x) cout << "0 0\n";
			else if( y / x == 1) cout << "1 1" << endl;
			else  
			{
				int t = y / x;
				bool flag = false;
				for (int b = 2; b <= t; b ++)
				{
					for (int a = 1; pow(b, a) <= t; a ++)
					{
						int res = 1;
						for (int k = 1; k <= a; k ++ )
							res *= b;
						if (res == t)
						{
							flag = true;
							cout << a << ' ' << b << endl;
							break;
						}
					}
					if (flag)
						break;
				}
				if (!flag) cout << "0 0\n";
			}
		}
	}
	return 0;
}