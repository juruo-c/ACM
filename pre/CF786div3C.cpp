#include <iostream>

using namespace std;

int main()
{
	int t;cin >> t;
	while (t --)
	{
		string s1, s2;
		cin >> s1 >> s2;
		bool flag = false;
		for (int i = 0; i < s2.size(); i ++ )
			if (s2[i] == 'a') 
			{
				flag = true;
				break;
			}
		if (flag)
		{
			if (s2.size() != 1)
				cout << -1 << endl;
			else cout << 1 << endl;
		}
		else
		{
			long long ans = 1;
			for (int i = 0; i < s1.size(); i ++ )
				ans *= 2;
			cout << ans << endl;
		}
		
	}
	return 0;
}