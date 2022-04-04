#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		string s;
		int n;cin >> n;
		cin >> s;
		int ans = 0;
		int c1 = 0;
		bool flag = false;
		for (int i = 0; i < s.size(); i ++ )
			if (s[i] == '0')
			{
				if (flag)
					ans += max(0, 2 - c1);
				flag = true;
				c1 = 0;
			}
			else
				c1 ++;
		cout << ans << endl;
	}
	return 0;
}