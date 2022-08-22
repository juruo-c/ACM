#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 305, INF = 0x3f3f3f3f;

int n;
int l[N], c[N];
unordered_map<int, bool> vis;
unordered_map<int, int> dis;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

void dij()
{
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0, 0});
	dis[0] = 0;

	while (!q.empty())
	{
		auto t = q.top();
		q.pop();
		int u = t.second;
		int d = t.first;

		if (u == 1) break;

		if (vis[u]) continue;
		vis[u] = true;

		for (int i = 1; i <= n; i ++ )
		{
			int v = gcd(u, l[i]), w = c[i];
			if (dis.find(v) == dis.end()) dis[v] = INF;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}

	}

}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &l[i]);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);

	dij();

	if (dis.find(1) != dis.end()) printf("%d\n", dis[1]);
	else puts("-1");

	return 0;
}