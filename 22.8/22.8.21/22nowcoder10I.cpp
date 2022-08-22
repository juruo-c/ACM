#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_map>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1000005;
int n, m;
int a[N], b[N];
unordered_map<int, int> vis;
unordered_map<int, PII> exist;
struct Node
{
    int id, num;
    bool operator < (const Node& b) const
    {
        return num < b.num;
    }
    bool operator < (const Node& b) const
    {
        return num == b.num;
    }
}A[N], B[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &m);
    int p1 = -1, p2 = -1, p3 = -1, p4 = -1;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        A[i].num = a[i], A[i].id = i;
        if (vis[a[i]]) p1 = vis[a[i]], p2 = i;
        else vis[a[i]] = i;
    }
    vis.clear();
    for (int i = 1; i <= m; i ++ )
    {
        scanf("%d", &b[i]);
        B[i].num = b[i], B[i].id = i;
        if (vis[b[i]]) p3 = vis[b[i]], p4 = i;
        else vis[b[i]] = i;
    }

    if (p1 != -1 && p3 != -1)
    {
        printf("%d %d %d %d\n", p1, p2, p3, p4);
        return 0;
    }

    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + m);
    n = unique(A + 1, A + 1 + n) - A - 1;
    m = unique(B + 1, B + 1 + m) - B - 1;

    bool flag = false;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            int t = A[i].num + B[i].num;
            if (exist.find(t) != exist.end())
            {
                auto tt = exist[t];
                printf("%d %d %d %d\n", tt.first, i, tt.second, j);
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    if (!flag) puts("-1");

    return 0;
}
