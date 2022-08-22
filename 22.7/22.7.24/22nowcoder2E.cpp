#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n;
int inv[N];

void init()
{
    inv[1] = 1;
    for (int i = 2; i <= n; i ++ )
        inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
}

int main()
{



    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t --)
    {
        
    }
    return 0;
}
