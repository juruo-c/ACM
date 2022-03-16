//https://www.acwing.com/problem/content/245/

#include <iostream>

using namespace std;

const int N = 100005;

int n;
int a[N], c[N];
int ans[N];

void add(int x, int k)
{
    for (int i = x; i <= n; i += (i & -i))
        c[i] += k;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= (i & -i))
        res += c[i];
    return res;
}

int ask(int x)
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (query(mid) >= x) r = mid;
        else if(query(mid) < x) l = mid + 1;
    }
    return r;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++ )
        scanf("%d", &a[i]), add(i, 1);
    add(1, 1);

    for (int i = n; i >= 1; i -- )
    {
        ans[i] = ask(a[i] + 1);
        add(ans[i], -1);
    }
    for (int i = 1; i <= n; i ++ )
        printf("%d\n", ans[i]);

    return 0;
}

#include <iostream>

using namespace std;

const int N = 100005;

int n;
int a[N], c[N];
int ans[N];

void add(int x, int k)
{
    for (int i = x; i <= n; i += (i & -i))
        c[i] += k;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= (i & -i))
        res += c[i];
    return res;
}

int ask(int x)
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (query(mid) >= x) r = mid;
        else if(query(mid) < x) l = mid + 1;
    }
    return r;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++ )
        scanf("%d", &a[i]), add(i, 1);
    add(1, 1);

    for (int i = n; i >= 1; i -- )
    {
        int p = 0, sum = 0;
        for (int j = 20; j >= 0; j --)
        {
            if (p + (1 << j) <= n && sum + c[p + (1 << j)] < a[i] + 1)
            {
                sum += c[p + (1 << j)];
                p += (1 << j);
            }
        }
        ans[i] = p + 1;
        add(ans[i], -1);
    }

    for (int i = 1; i <= n; i ++ )
        printf("%d\n", ans[i]);

    return 0;
}
