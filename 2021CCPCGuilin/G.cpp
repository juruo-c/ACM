#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1000005;

int n;
char s[N];

bool check(int x)
{
    int r = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (s[i] == '1')
        {
            int tl = i - x + 1, tr = i + x - 1;
            if (tl <= r + 1) r = tr + 1;
            else if(tl - 1 <= r + 1) r = tr;
            else return false;
        }
    }
    return r >= n;
}

int main()
{
    int _;scanf("%d", &_);
    while(_ --)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);

        bool flag = true;
        for (int i = 1; i <= n; i ++ )
            if (s[i] != '1')
            {
                flag = false;
                break;
            }
        if (flag)
        {
            puts("0");
            continue;
        }

        int l = 1, r = 1e9;
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