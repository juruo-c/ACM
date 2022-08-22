#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> Map;
	int cnt = 0;
	for (char i = 'a'; i <= 'z'; i ++ )
		for (char j = 'a'; j <= 'z'; j ++ )
		{
			if (i == j) continue;
			string s;
			s += i;
			s += j;
			Map[s] = ++ cnt;
		}

	int t;cin >> t;
	while (t --)
	{
		string s;
		cin >> s;
		cout << Map[s] << endl;
	}
	return 0;
}