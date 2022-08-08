#include <iostream>

using namespace std;

bool vis[10];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i ++ )
		vis[s[i] - '0'] = true;

	for (int i = 0; i <= 9; i ++ )
		if (vis[i] == 0)
		{
			cout << i << endl;
			break;
		}

	return 0;
}