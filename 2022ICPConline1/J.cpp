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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int x, y;
    scanf("%d%d", &x, &y);
    x --;
    while (x > y)
    {
        printf("%d %d\n", 1, y);
        x --;
    }
    vector<PII> ans;
    int p = y;
    while(x --)
    {
        ans.push_back(make_pair(1, p));
        p += y - 1;
    }
    for (int i = ans.size() - 1; i >= 0; i -- )
        printf("%d %d\n", ans[i].first, ans[i].second);
    printf("%d %d\n", 1, 1);
    return 0;
}
