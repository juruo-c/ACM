#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100005;

int n;
char s[N];

vector<int> sub(vector<int>& a, vector<int>& b)
{
	vector<int> res(a.size());
	if (b.size() < a.size()) b.push_back(0);
	for (int i = 0; i < a.size(); i ++ )
	{
		if (a[i] < b[i]) a[i] += 10, a[i + 1] --;
		res[i] = a[i] - b[i];
	}
	while (res.back() == 0) res.pop_back();
	return res;
}

int main()
{
	int t; cin >> t;
	while (t --)
	{
		cin >> n;
		string s;
		cin >> s;
		vector<int> num;
		for (int i = 0; i < s.size(); i ++ )
			num.push_back(s[i] - '0');
		vector<int> ans;
		if (s[0] == '9')
		{
			for (int i = 0; i <= s.size(); i ++ )
				ans.push_back(1);
		}
		else 
		{
			for (int i = 0; i < s.size(); i ++ )
				ans.push_back(9);		
		}
		reverse(num.begin(), num.end());
		

		ans = sub(ans, num);
		reverse(ans.begin(), ans.end());
		for (auto x : ans)
			cout << x;
		cout << endl;
	}
	return 0;
}