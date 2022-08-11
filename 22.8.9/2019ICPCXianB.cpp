#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_map>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1587400;

LL n, m;
int happy_birthday;
LL d[N + 5], p[N + 5], num[N + 5], phi[N + 5];
bool vis[N + 5];
int inv2;
unordered_map<LL, LL> phiS;

LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % happy_birthday;
        a = a * a % happy_birthday;
        b >>= 1;
    }
    return res;
}

void pre()
{
    phi[1] = d[1] = 1;
    for (int i = 2; i <= N; i ++ )
    {
        if (!vis[i])
        {
            p[ ++ p[0]] = i;
            phi[i] = i - 1;
            d[i] = 2, num[i] = 1;
        }
        for (int j = 1; j <= p[0] && i * p[j] <= N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                phi[i * p[j]] = phi[i] * p[j] % happy_birthday;
                num[i * p[j]] = num[i] + 1;
                d[i * p[j]] = d[i] * qpow(num[i * p[j]], happy_birthday - 2) % happy_birthday * (num[i * p[j]] + 1) % happy_birthday;
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1) % happy_birthday;
            num[i * p[j]] = 1;
            d[i * p[j]] = d[i] * 2 % happy_birthday;
        }
    }
    for (int i = 1; i <= N; i ++ )
        phi[i] = (phi[i] + phi[i - 1]) % happy_birthday;
    for (int i = 1; i <= N; i ++ )
        d[i] = (i * d[i] % happy_birthday + d[i - 1] ) % happy_birthday;
}

LL sum_d(LL n)
{
    if (n <= N) return d[n];
    LL ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans + (r - l + 1) * (r + l) / 2 % happy_birthday * ((n / l + 1) * (n / l) / 2 % happy_birthday) % happy_birthday) % happy_birthday;
    }
    return ans;
}

LL sum_phi(LL n)
{
    if (n <= N) return phi[n];
    if (phiS.find(n) != phiS.end()) return phiS[n];
    LL ans = (n + 1) * n / 2 % happy_birthday;
    for (LL l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans - (r - l + 1) * sum_phi(n / l) % happy_birthday + happy_birthday) % happy_birthday;
    }
    return phiS[n] = ans;
}

LL calc(LL n)
{
    return (2 * sum_phi(n) % happy_birthday - 1 + happy_birthday) % happy_birthday;
}

int main()
{
    
    cin >> n >> m >> happy_birthday;
    happy_birthday --;
    pre();
    inv2 = qpow(2, happy_birthday - 2);

    LL ans = 0;
    for (LL l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans + (sum_d(r) - sum_d(l - 1) + happy_birthday) % happy_birthday * calc(n / l) % happy_birthday) % happy_birthday;
    }

    happy_birthday ++;
    cout << qpow(m, ans) << endl;

    return 0;
}
