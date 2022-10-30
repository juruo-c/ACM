#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

LL p, q;

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

struct Num
{
    LL num;
    int a[20];
    int b[10];
    Num(){}
    Num(LL x) 
    {
        memset(a, 0, sizeof a);
        num = x;
        while (x)
        {
            a[++ a[0]] = x % 10;
            x /= 10;
        }    
        
        for (int i = 0; i < 10; i ++ )
            b[i] = 0;
        for (int i = 1; i <= a[0]; i ++ )
            b[a[i]] ++;
    }
};

bool check(Num& P, Num& Q, Num& p, Num& q)
{
    for (int i = 1; i <= 9; i ++ )
        if (p.b[i] - P.b[i] != q.b[i] - Q.b[i])
            return false;
    return true;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%lld%lld", &p, &q);

        Num P(p), Q(q);

        LL ansP = p, ansQ = q;
        int n = P.a[0];
        for (int i = 1; i < (1 << n); i ++ )
        {
            LL tmp = 0;
            for (int j = n - 1; j >= 0; j -- )
                if (i >> j & 1) tmp = tmp * 10 + P.a[j + 1];
            

            if (tmp == 0) continue;

            LL t1 = gcd(p, q);
            LL t2 = gcd(tmp, p / t1);

            if (t1 * t2 != p) continue;

            Num newP(tmp);
            Num newQ((q / t1) * (tmp / t2));

            if (check(newP, newQ, P, Q))
            {
                if (tmp < ansP)
                {
                    ansP = tmp;
                    ansQ = newQ.num;
                }
            }
        }

        printf("%lld %lld\n", ansP, ansQ);
    }
    return 0;
}