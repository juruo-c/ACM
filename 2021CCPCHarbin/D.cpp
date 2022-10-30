#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL p, q;
int n, m;
int P[20];
int Q[20];
int sub[10];

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

bool check(LL nq)
{
    for (int i = 0; i < m; i ++ )
    {
        if (nq && Q[i] == nq % 10)
        {
            nq /= 10;
            continue;
        }
        else if (nq == 0 && Q[i] == 0 && !sub[0]) continue;
        if (sub[Q[i]])
            sub[Q[i]] --;
        else return false;
    }
    for (int i = 0; i < 10; i ++ )
        if (sub[i]) return false;
    return true;
}

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%lld%lld", &p, &q);
        LL x = p;
        n = 0;
        while (x)
        {
            P[n ++] = x % 10;
            x /= 10;
        }
        x = q;
        m = 0;
        while (x)
        {
            Q[m ++] = x % 10;
            x /= 10;
        }
        
        LL g = gcd(p, q);
        LL ap = p, aq = q;
        for (int i = 1; i < (1 << n); i ++)
        {
            for (int j = 0; j < 10; j ++ )
                sub[j] = 0;
            
            LL newp = 0;
            for (int j = n - 1; j >= 0; j -- )
                if (i >> j & 1) newp = newp * 10 + P[j];
                else sub[P[j]] ++;
            
            if (newp == 0) continue;
            if (newp % (p / g)) continue;
            
            LL newq = (newp / (p / g)) * (q / g);
            if (!check(newq)) continue;

            ap = min(ap, newp);
            aq = min(aq, newq);
        }

        printf("%lld %lld\n", ap, aq);

    }
    return 0;
}