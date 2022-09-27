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

const int N = 2000005, mod = 998244353;

struct Mint
{
    int num;
    Mint(){num = 0;}
    Mint(int x):num(x){}
    Mint operator - (const Mint& b) const 
    {
        return Mint((num - b.num + mod) % mod);
    }
    Mint operator + (const Mint& b) const 
    {
        return Mint((num + b.num) % mod);
    }
    Mint operator * (const Mint& b) const 
    {
        return Mint((1LL * num * b.num) % mod);
    }
    Mint operator + (const int & b) const 
    {
        return Mint((num + b) % mod);
    }
    Mint operator * (const int& b) const 
    {
        return Mint(1LL * num * b % mod);
    }
};

char s[N];
int l[N], r[N];
Mint I[N], C[N], P[N];
Mint IC[N], CP[N], PC[N];
Mint ICP[N], CPC[N];
Mint ICPC[N];

Mint query(int l, int r)
{
    Mint i = I[r] - I[l];
    Mint c = C[r] - C[l];
    Mint p = P[r] - P[l];
    Mint ic = IC[r] - IC[l] - I[l] * c;
    Mint cp = CP[r] - CP[l] - C[l] * p;
    Mint pc = PC[r] - PC[l] - P[l] * c;
    Mint icp = ICP[r] - ICP[l] - IC[l] * p - I[l] * cp;
    Mint cpc = CPC[r] - CPC[l] - C[l] * pc - CP[l] * c;
    Mint icpc = ICPC[r] - ICPC[l] - I[l] * cpc - IC[l] * pc - ICP[l] * c;
    // printf("i = %d c = %d p = %d ic = %d cp = %d\n", i, c, p, ic, cp);
    // printf("icp = %d cpc = %d\n", icp, cpc);
    return icpc;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    int x, a, b, p;
    scanf("%d%d%d%d", &x, &a, &b, &p);

    for (int i = 1; i <= n; i ++ )
    {
        I[i] = I[i - 1], C[i] = C[i - 1], P[i] = P[i - 1];
        IC[i] = IC[i - 1], CP[i] = CP[i - 1], PC[i] = PC[i - 1];
        ICP[i] = ICP[i - 1], CPC[i] = CPC[i - 1];
        ICPC[i] = ICPC[i - 1];
        if (s[i] == 'I')
            I[i] = I[i] + 1;
        else if(s[i] == 'C')
        {
            C[i] = C[i] + 1;
            PC[i] = PC[i] + P[i - 1];
            IC[i] = IC[i] + I[i - 1];
            CPC[i] = CPC[i] + CP[i - 1];
            ICPC[i] = ICPC[i] + ICP[i - 1];
        }
        else if(s[i] == 'P')
        {
            P[i] = P[i] + 1;
            CP[i] = CP[i] + C[i - 1];
            ICP[i] = ICP[i] + IC[i - 1];
        }
    }

    Mint sum(0);
    for (int i = 1; i <= q; i ++ )
    {
        x = (1LL * a * x + b) % p;
        l[i] = x % n + 1;
    }
    for (int i = 1; i <= q; i ++ )
    {
        x = (1LL * a * x + b) % p;
        r[i] = x % n + 1;
    }

    for (int i = 1; i <= q; i ++ )
    {
        if (l[i] > r[i]) swap(l[i], r[i]);
        // printf("%d %d\n", l[i], r[i]);
        // printf("ans = %d\n", query(l[i] - 1, r[i]).num);
        sum = sum + query(l[i] - 1, r[i]).num;
        
    }   

    printf("%d\n", sum.num);

    return 0;
}
