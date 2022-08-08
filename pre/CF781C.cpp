#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 200005;

int n;
int sum[N];

int main()
{
	int t;scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
			sum[i] = 0;
		for (int i = 2; i <= n; i ++ )
		{
			int x;
			scanf("%d", &x);
			sum[x] ++;
		}	

		vector<int> v;
		v.push_back(1);
		for (int i = 1; i <= n; i ++ )
			if (sum[i]) v.push_back(sum[i]);
		sort(v.begin(), v.end());

		priority_queue<int> q;

		int ans = v.size();
		for (int i = 0; i < ans; i ++ )
		{
			v[i] -= (i + 1);
			if (v[i]) q.push(v[i]);
		}

		int res = 0;
		while (!q.empty() && q.top() > res)
		{
			int t = q.top();
			q.pop();
			q.push(t - 1);
			res ++;
		}

		printf("%d\n", res + ans);
	}
	return 0;
}



