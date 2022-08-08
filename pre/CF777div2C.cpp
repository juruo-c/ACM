#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 105;

int n, m;
char g[N][N];

int main()
{
	int t;cin >> t;
	while (t --)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i ++ )
			cin >> g[i];
		if (g[0][0] == '1')
		{
			cout << -1 << endl;
			continue;
		}

		vector<pair<PII, PII> > v;
		for (int i = n - 1; i >= 0; i -- )
			for (int j = m - 1; j >= 0; j -- )
				if (g[i][j] == '1' )
				{
					int ux = i - 1, uy = j, dx = i, dy = j;
					if (!i) ux = i, uy = j - 1;
					v.push_back({{ux + 1, uy + 1}, {dx + 1, dy + 1}});
				}

		cout << v.size() << endl;
		for (auto x : v)
			cout << x.first.first << " " << x.first.second << " " << x.second.first << " " << x.second.second << endl;
	}
	return 0;
}