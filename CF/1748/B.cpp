#include <bits/stdc++.h>
#define ZYCMH

using namespace std;

const int N = 100005;

int n;
char s[N];
int cnt[10][N];

bool check(int l, int r)
{
    int c = 0;
    for (int i = 0; i < 10; i ++ )
        if (cnt[i][r] - cnt[i][l - 1]) c ++;
    for (int i = 0; i < 10; i ++ )
        if (cnt[i][r] - cnt[i][l - 1] > c) return false;
    return true;
}

int main()
{

    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);

        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 0; j < 10; j ++ )
                cnt[j][i] = cnt[j][i - 1];
            cnt[s[i] - '0'][i] ++;
        }

        long long ans = 0;
        for (int i = 1; i <= min(100, n); i ++ )
        {
            for (int l = 1; l + i - 1 <= n; l ++ )
            {
                int r = l + i - 1;
                if (check(l, r))
                    ans ++;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}