#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 600005;

int n, m;
int c[N];
int a[N];
char s[N];

void update(int x)
{
    for (int i = x; i <= n; i += (i & -i))
        c[i] ++;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= (i & -i))
        res += c[i];
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    
    long long ans = 0;
    for (int i = n; i >= 1; i -- )
    {
        update(a[i]);
        ans += query(a[i] - 1);
    }

    printf("%lld\n", ans);
    ans %= 10;

    deque<int> q;
    for (int i = 1; i <= n; i ++ )
        q.push_back(a[i]);
    int f = 0;

    scanf("%s", s);
    for (int i = 0; i < m; i ++ )
    {
        if (s[i] == 'R')
        {
            f ^= 1;
            ans = (1LL * n * (n - 1) / 2 % 10 - ans + 10) % 10;
            printf("%d", ans); 
        }
        else 
        {
            int t;
            if (!f)
            {
                t = q.front();
                q.pop_front();
            }
            else 
            {
                t = q.back();
                q.pop_back();
            }
            ans = (ans - (t - 1) + (n - t)) % 10;
            ans = (ans + 10) % 10;
            printf("%d", ans);

            if (!f)
                q.push_back(t);
            else 
                q.push_front(t);
        }
    }

    return 0;
}