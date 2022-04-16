#include <iostream>

using namespace std;

int main()
{
	int t;cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		if (n < 2)
		{
			cout << n << endl;
			continue;
		}
		int t = 2;
		string ans = "";
		while (n)
		{
			if (n == 1 && t == 2) ans = "1" + ans, n = 0;
			else 
			{
				n -= t;
				ans += char(t + '0');
			}
			if (t == 2) t = 1;
			else t = 2;
		}
		cout << ans << endl;
	}
	return 0;
}