#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 300005;

int n, k, d;
struct edge
{
	int to, next, id;
}e[N << 1];
int head[N], cnt;
int dis[N];
bool vis[N];

void add(int u, int v, int id)
{
	e[++ cnt] = {v, head[u], id};
	head[u] = cnt;
}

int main()
{
	scanf("%d%d%d", &n, &k, &d);
	memset(dis, -1, sizeof dis);
	queue<int> q;
	for (int i = 1; i <= k; i ++ )
	{
		int x;scanf("%d", &x);
		q.push(x);
		dis[x] = 0;
	}
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v, i);
		add(v, u, i);
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (dis[v] == -1)
			{
				vis[e[i].id] = true;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

	vector<int> E;
	for (int i = 1; i < n; i ++ )
		if (!vis[i]) E.push_back(i);

	printf("%d\n", E.size());
	for(auto x : E)
		printf("%d ", x);

	return 0;	
}