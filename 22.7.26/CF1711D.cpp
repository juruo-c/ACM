#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
// #define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005, mod = 1000000007, INF = 0x3f3f3f3f;

int n, m;
vector<PII> v;
int x[N], p[N];
LL mi, mx;

bool cmp(PII& a, PII& b)
{
    return a.first < b.first;
}

void solve(int pos, LL val)
{
    if (val <= m) return;
    mi = min(mi, pos - val + m);
    mx = max(mx, pos + val - m);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &m);
        v.clear();
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d%d", &x[i], &p[i]);
            v.push_back({x[i] - p[i] + 1, 1});
            v.push_back({x[i] + 1, -2});
            v.push_back({x[i] + p[i] + 1, 1});
        }

        sort(v.begin(), v.end(), cmp);
        v.push_back({-INF, 0});

        LL sum = 0, d = 0;
        mi = 1e18, mx = -1e18;
        for (int i = 0; i < v.size() - 1; i ++ )
        {   
            d += v[i].second;
            if (v[i].first != v[i + 1].first)
            {
                solve(v[i].first, sum + d);
                solve(v[i + 1].first - 1, sum + d * (v[i + 1].first - v[i].first));
            }
            sum += d * (v[i + 1].first - v[i].first);
        }

        for (int i = 1; i <= n; i ++ )
        {
            if (x[i] - p[i] <= mi && x[i] + p[i] >= mx) printf("1");
            else printf("0");
        }
        puts("");

    }
    return 0;
}
