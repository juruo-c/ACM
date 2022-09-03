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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    LL a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    LL yellow = 2 * x + y;
    LL blue = 3 * z + y;
    cout << max(0LL, yellow - a) + max(0LL, blue - b);
    return 0;
}
