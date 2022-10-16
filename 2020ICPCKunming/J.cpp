#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

int n;
int p[N];
int pos[N];

bool check0()
{
    for (int i = 1; i <= n; i ++ )
        if (p[i] != i)
            return false;
    return true;
}

bool check1()
{
    for (int i = 1; i <= n; i ++ )
        if (p[p[i]] != i)
            return false;
    printf("1\n");
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (p[i] != i)
            cnt ++;
    printf("%d", cnt / 2);
    for (int i = 1; i <= n; i ++ )
        if (p[i] != i && i < p[i])
            printf(" %d %d", i, p[i]);
    puts("");
    return true;
}

void solve()
{
    printf("2\n");
    vector<PII> ans;
    for (int i = 1; i <= n; i ++ )
        if (p[p[i]] != i)
        {
            int j = i;
            while (p[p[j]] != j)
            {
                swap(p[pos[j]], p[p[j]]);
                ans.push_back(make_pair(pos[j], p[j]));
                j = pos[j];
            }
        }

    printf("%d", (int)ans.size());
    int sz = ans.size();
    for (int i = 0; i < sz; i ++ )
        printf(" %d %d", ans[i].first, ans[i].second);
    puts("");
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (p[i] != i)
            cnt ++;
    printf("%d", cnt / 2);
    for (int i = 1; i <= n; i ++ )
        if (p[i] != i && i < p[i])
            printf(" %d %d", i, p[i]);
    puts("");
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &p[i]), pos[p[i]] = i;
    
    if (check0())
    {
        puts("0");
        return 0;
    }

    if (check1())
        return 0;

    solve();
    
    return 0;
}
