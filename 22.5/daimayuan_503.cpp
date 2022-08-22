//http://oj.daimayuan.top/course/10/problem/503
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 100005;

PII works[N];
int n;
int cnt;

int main()
{
    scanf("%d", &n);
    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int d, p;
        scanf("%d%d", &d, &p);
        if (d <= n)
            works[++ cnt] = {d, p};
        else ans += p;
    }
    sort (works + 1, works + 1 + n);
    reverse(works + 1, works + 1 + n);

    priority_queue<int> q;
    for(int i = n, j = 1; i >= 1; i -- )
    {
        while(works[j].first == i) q.push(works[j ++].second);
        if (q.size())
            ans += q.top(), q.pop();
    }

    printf("%lld\n", ans);

    return 0;
}
