#include <iostream>
#include <algorithm>

using namespace std;

const int N = 16;

int n, k;
int cnt[26];
string s[N];


int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i ++ )
		cin >> s[i];

	int ans = 0;
	for (int i = 0; i < (1 << n); i ++ )
	{
		for (int j = 0; j < 26; j ++ ) cnt[j] = 0;
		for (int j = 0; j < n; j ++)
			if (i & (1 << j))
			{
				for (auto c : s[j])
					cnt[c - 'a'] ++;
			}
		int res = 0;
		for (int j = 0; j < 26; j ++ )
			if (cnt[j] == k) res ++;
		ans = max(ans, res);
	}

	cout << ans << endl;
	return 0;
}