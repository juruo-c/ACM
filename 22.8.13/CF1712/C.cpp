#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int N = 100005;

int a[N];
vector<int> pos[N];
int lpos[N], rpos[N];

int main()
{
	int t;
	scanf("%d", &t );
	while (t --)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) pos[i].clear();
		for (int i = 1; i <= n; i ++ ) lpos[i] = n + 1, rpos[i] = 0;
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%d", &a[i]);
			lpos[a[i]] = min(lpos[a[i]], i);
			rpos[a[i]] = max(rpos[a[i]], i);
			pos[a[i]].push_back(i);
		}

		a[n + 1] = n + 1;
		int p = 0;
		for (int i = 1; i <= n; i ++ )
			if (rpos[a[i]] - lpos[a[i]] + 1 != pos[a[i]].size() || a[i] > a[i + 1])
				p = i;

		set<int> s;
		for (int i = 1; i <= p; i ++ )
			s.insert(a[i]);

		printf("%d\n", s.size());
	}
	return 0;
}