#include <iostream>
#include <map>

using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, int> cnt;

	bool smallflag = false, bigflag = false;
	for (int i = 0; i < s.size(); i ++ )
	{
		cnt[s[i]] ++;
		if ('a' <= s[i] && s[i] <= 'z') smallflag = true;
		if ('A' <= s[i] && s[i] <= 'Z') bigflag = true;
	}
	bool flag = true;
	for (char i = 'a'; i <= 'z'; i ++ )
		if (cnt[i] >= 2) flag = false;
	for (char i = 'A'; i <= 'Z'; i ++ )
		if (cnt[i] >= 2) flag = false;

	if (flag && smallflag && bigflag) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}