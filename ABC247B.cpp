#include <iostream>
#include <set>

using namespace std;

const int N = 105;

int n;
pair<string, string> a[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i].first >> a[i].second;

	bool flag = true;
	for (int i = 1; i <= n; i ++ )
	{
		bool f1 = true, f2 = true;
		for (int j = 1; j <= n; j ++ )
		{
			if (i == j) continue;
			if (a[j].first == a[i].first || a[j].second == a[i].first) f1 = false;
			if (a[j].first == a[i].second || a[j].second == a[i].second) f2 = false;
		}

		if (!f1 && !f2)
		{
			flag = false;
			break;
		}
	}

	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}