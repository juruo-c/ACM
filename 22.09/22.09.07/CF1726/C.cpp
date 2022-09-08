#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;

int stk[N], top;
char s[N];
int match[N];
int ans;

void dfs(int l, int r)
{
    int cnt = 0;
    while(l <= r)
    {
        dfs(l + 1, match[l] - 1);
        l = match[l] + 1;
        cnt ++;
    }
    if (cnt) ans ++;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int i = 1; i <= 2 * n; i ++ )
            if (s[i] == '(') stk[++ top] = i;
            else match[stk[top --]] = i;

        // for (int i = 1; i <= 2 * n; i ++ )
        //     cout << match[i] << " ";

        ans = 0;
        dfs(1, 2 * n);
        printf("%d\n", ans);
    }
    return 0;
}
