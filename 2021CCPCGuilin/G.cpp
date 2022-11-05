#include <iostream>

using namespace std;

const int N = 1000005;

int n;
char s[N];
int dis[N];
int id[N];

struct One
{
    int l, r;
}one[N];
int cnt;

bool check(int x)
{
    for (int i = 1; i <= n; i ++ )
        dis[i] = 1e9;

    for (int i = 1; i <= cnt; i ++ )
    {
        int len = one[i].r - one[i].l + 1;
        for (int j = one[i - 1].r + 1; j < one[i].l; j ++ )
        {
            int d = one[i].l - j;
            if (dis[j] > d)
            {
                dis[j] = d;
                if (len == 1)
                    id[j] = i;
            }
        }
        for (int j = one[i].r + 1; j < one[i + 1].l; j ++ )
        {
            int d = j - one[i].r;
            if (dis[j] > d)
            {
                dis[j] = d;
                if (len == 1)
                    id[j] = i;
            }
        }
    }

    for (int i = 1; i <= cnt; i ++ )
    {
        int len = one[i].r - one[i].l + 1;
        if (len == 1)
        {
            
        }
    }
}

int main()
{
    int _;
    while(_ --)
    {
        cnt ++;
        scanf("%d", &n);
        scanf("%s", s + 1);

        one[0].l = 0, one[0].r = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (s[i] == '1')
            {
                int j = i;
                while (j <= n && s[j] == '1') j ++;
                one[++ cnt] = {i, j - 1};
                i = j - 1;
            }
        }
        one[cnt + 1].l = n + 1, one[cnt + 1].r = n + 1;

        int l = 0, r = 1e9;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        printf("%d\n", r);

    }
    return 0;
}