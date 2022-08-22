#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t = 1;
    while (t --)
    {
        LL H, M, A;
        cin >> H >> M >> A;
        LL g = gcd(H - 1, H * M);
        cout << min(H * M, g * (2 * A / g + 1));
    }
    return 0;
}
