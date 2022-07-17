#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int N = 200005;

int n, k;
int cnt;
int ans[N];
int belong[N];
set<int> s;
vector<int> pire[N];

int main()
{
	memset(ans, -1, sizeof ans);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++ )
	{
		int p;
		scanf("%d", &p);
		if (!s.size())
		{
			s.insert(p);
			pire[++ cnt].push_back(p);
			belong[p] = cnt;
		}
		else
		{
			auto it = s.lower_bound(p);
			if (it == s.end())
			{
				pire[++ cnt].push_back(p);
				belong[p] = cnt;
			}
			else
			{
				int x = *it;
				pire[belong[x]].push_back(p);
				belong[p] = belong[x];
				s.erase(it);
			}
			s.insert(p);
		}
		if (pire[belong[p]].size() == k)
		{
			for (auto x : pire[belong[p]])
			{
				ans[x] = i;
				if (s.count(x))
					s.erase(s.find(x));
			}
		}
	}
	for (int i = 1; i <= n; i ++ )
		cout << ans[i] << endl;
	return 0;
}