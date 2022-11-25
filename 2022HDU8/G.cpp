#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 50005;

int n;
int p[N];
int pos[N];
vector<PII> edge[N];
int fa[N];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++ ) scanf("%d", &p[i]), pos[p[i]] = i;
        
        for (int i = 1; i < n; i ++ ) edge[i].clear();
        
        for (int i = 1; i < sqrt(n); i ++ )
            for (int j = 1; j + i <= n; j ++ )
            {
                if (1LL * i * abs(p[j] - p[j + i]) <= n - 1)
                    edge[i * abs(p[j] - p[j + i])].push_back({j, j + i});
                if (1LL * i * abs(pos[j] - pos[j + i]) <= n - 1)
                    edge[i * abs(pos[j] - pos[j + i])].push_back({pos[j], pos[j + i]});
            }

        for (int i = 1; i <= n; i ++ ) fa[i] = i;
        long long ans = 0;
        for (int i = 1; i < n; i ++ )
        {
            for (auto e : edge[i])
            {
                int u = getf(e.first), v = getf(e.second);
                if (u != v)
                {
                    ans += i;
                    fa[u] = v;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}