#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <list>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n, x;
struct List
{
    int pre, next;
    int data;
}a[N];
bool vis[N];

bool check(int a, int b)
{
    // cout << a << " " << b << endl;
    return a == b || (a + b == x);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i].data);
    a[1].pre = n, a[1].next = 2;
    a[n].next = 1, a[n].pre = n - 1;
    for (int i = 2; i < n; i ++ )
        a[i].pre = i - 1, a[i].next = i + 1;
    
    int cur = 1;
    int ans = 0;
    int len = n;
    while (true)
    {
        if (vis[cur]) break;
        vis[cur] = true;
        if (len <= 1) break;
        if (check(a[cur].data, a[a[cur].next].data))
        {
            len -= 2;
            ans ++;
            int nxt = a[a[cur].next].next;
            int pre = a[cur].pre;
            a[pre].next = nxt;
            a[nxt].pre = pre;
            cur = nxt;
            while (len >= 2 && check(a[cur].data, a[a[cur].pre].data))
            {
                len -= 2;
                ans ++;
                int nxt = a[cur].next;
                int pre = a[a[cur].pre].pre;
                a[pre].next = nxt;
                a[nxt].pre = pre;
                cur = nxt;
            }
        }
        cur = a[cur].next;
    }

    printf("%d\n", ans);

    return 0;
}
