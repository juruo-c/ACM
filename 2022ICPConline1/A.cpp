#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

char s[N];
int st[N], ed[N];
int sum[N];
int s0[N];

int main()
{

    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);

    int stt = 0, edd = 0;
    for (int i = 1; i <= n; i ++ )
    {
        sum[i] = sum[i - 1];
        s0[i] = s0[i - 1];
        if (s[i] == '1')
        {
            if (stt == 0)
                stt = i;
            st[i] = stt;
        }
        else
        {
            s0[i] ++;
            if (stt)
            {
                int len = i - stt;
                sum[i] += len / 2 + (len % 2) * 2;
                stt = 0;
            }
        }
    }
    for (int i = n; i >= 1; i -- )
    {
        if (s[i] == '1')
        {
            if (edd == 0)
                edd = i;
            ed[i] = edd;
        }
        else 
        {
            if (edd) 
                edd = 0;
        }
    }

    // for (int i = 1; i <= n; i ++ )
    //     cout << st[i] << " " << ed[i] << endl;

    for (int i = 1; i <= q; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int len = r - l + 1;
        if (s[l] == '1') l = ed[l] + 1;
        if (s[r] == '1') r = st[r] - 1;
        if (l > r) puts("0");
        else
        {
            int cnt = len - (r - l + 1);
            cnt = cnt / 2 + (cnt % 2) * 2;
            int c0 = s0[r] - s0[l - 1] - cnt;
            c0 -= sum[r] - sum[l];
            // cout << "c0 = " << c0 << endl;
            printf("%d\n", (c0 > 0 ? c0 / 3 : 0));
        }
    }

    return 0;
}