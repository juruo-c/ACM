#include <iostream>
#include <cstring>

using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		cin >> s + 1;
		int n = strlen(s + 1);

		if (n == 2)
		{
			cout << "YES" << endl;
			continue;
		}

		int c1 = 0, c2 = 0;
		s[1] = '(', s[n] = ')';
		for (int i = 1; i <= n; i ++ )
			if (s[i] == '(') c1 ++;
			else if(s[i] == ')') c2 ++;

		if (c1 == n / 2 || c2 == n / 2)
		{
			cout << "YES" << endl;
			continue;
		}
		else if(c1 == 0 && c2 == 0)
		{
			cout << "NO" << endl;
			continue;
		}

		int cur = 1;
		for (int i = 2; i <= n; i ++ )
		{
			if (s[i] == '(') cur ++;
			else if(s[i] == ')') cur --;
			else
			{
				if (cur == 0) cur ++, c1 ++;
				else 
				{
					cout << "NO" << endl;
					break;
				}
			}
			if (c1 == n / 2 || c2 == n / 2)
			{
				cout << "YES" << endl;
				break;
			}
		}
	}
	return 0;
}