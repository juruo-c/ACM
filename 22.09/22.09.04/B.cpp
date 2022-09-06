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

const int N = 100005, INF = 0x3f3f3f3f;
int a[N];
int ans[N];
struct TreeNode
{
    int l, r;
    int mi;
}t[N << 2];

void push_up(int i)
{
    t[i].mi = min(t[i << 1].mi, t[i << 1 | 1].mi);
}

void build(int i, int l, int r)
{
    t[i].l = l, t[i].r = r;
    if (l == r) 
    {
        t[i].mi = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
}

void update(int i, int pos)
{
    if (t[i].l == t[i].r)
    {
        t[i].mi = INF;
        return;
    }
    int mid = (t[i].l + t[i].r) >> 1;
    if (pos <= mid) update(i << 1, pos);
    else update(i << 1 | 1, pos);
    push_up(i);
}

void query(int i, int pos)
{
    if (t[i].l == t[i].r)
    {
        ans[pos] = t[i].l - pos - 1;
        return;
    }
    if (t[i << 1 | 1].mi < a[pos])
        query(i << 1 | 1, pos);
    else query(i << 1, pos);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);

    build(1, 1, n);

    for (int i = 1; i <= n; i ++ )
    {
        if (t[1].mi >= a[i])
            ans[i] = -1;
        else
            query(1, i);
        update(1, i);
    }
            
    for (int i = 1; i <= n; i ++ )
        printf("%d ", ans[i]);
    puts("");
    
    return 0;
}

