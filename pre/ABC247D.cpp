#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n;
deque<PII> q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		int op;scanf("%d", &op);
		if (op == 1)
		{
			int x, c;
			scanf("%d%d", &x, &c);
			q.push_back({x, c});
		}
		else
		{
			int c; scanf("%d", &c);
			LL ans = 0;
			int num = 0;
			PII t;
			while (num < c && q.size())
			{
				t = q.front();
				q.pop_front();
				num += t.second;
				ans += 1LL * t.first * t.second;
			}
			if (num > c)
			{
				q.push_front({t.first, num - c}); 
				ans -= 1LL * t.first * (num - c);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}