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

const int N = 200005;

int n;
struct edge
{
    int to, next;
}e[N], e2[N];
int head[N], cnt;
int head2[N], cnt2;
int d[N], d1[N], d2[N];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void add2(int u, int v)
{
    e2[++ cnt2] = {v, head2[u]};
    head2[u] = cnt2;
}

void dfs(int u)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        dfs(v);
        if (d[v] % 2 == 0)
            add2(v, u), d2[u] ++, d[u] --;
        else add2(u, v), d2[v] ++;
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    scanf("%d", &n);
    int rt;
    for (int i = 1; i <= n; i ++ )
    {
        int p;
        scanf("%d", &p);
        if (!p) 
        {
            rt = i;
            continue;
        }
        add(p, i);
        d[i] ++, d[p] ++;
        d1[i] ++, d1[p] ++;
    }

    dfs(rt);

    // for (int i = 1; i <= n; i ++ )
    // {
    //     cout << "i = " << i << endl;
    //     for (int j = head2[i]; j; j = e2[j].next)
    //     {
    //         int v = e2[j].to;
    //         cout << "v = " << v << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= n; i ++ )
    //     cout << i << " " << d2[i] << endl;

    queue<int> q;
    vector<int> ans;
    bool flag = true;
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (!d2[i])
        {
            if (d1[i] % 2)
            {
                flag = false;
                break;
            }
            else q.push(i), ans.push_back(i), cnt ++;
        }

    if (!flag) 
    {
        puts("NO");
        return 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head2[u]; i; i = e2[i].next)
        {
            int v = e2[i].to;
            d1[v] --;
            d2[v] --;
            if (!d2[v])
            {
                if (d1[v] % 2)
                {
                    puts("NO");
                    return 0;
                }
                else q.push(v), ans.push_back(v), cnt ++;
            }
        }
    }

    if (cnt < n)
    {
        puts("NO");
        return 0;
    }

    puts("YES");
    for (int i = 0; i < ans.size(); i ++ )
        printf("%d\n", ans[i]);

    return 0;
}
