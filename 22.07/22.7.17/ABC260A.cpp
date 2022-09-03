#include <iostream>

using namespace std;

int cnt[26];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i ++ )
		cnt[s[i] - 'a'] ++;
	for (int i = 0; i < 26; i ++ )
		if (cnt[i] == 1)
		{
			cout << (char)('a' + i) << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}